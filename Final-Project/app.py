import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session,Response, url_for
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash
from helpers import apology, login_required

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///users.db")

show_id=db.execute("CREATE TABLE IF NOT EXISTS users ( id INTEGER , username TEXT NOT NULL, hash TEXT NOT NULL,\
            PRIMARY KEY(id))")

show_id2=db.execute("CREATE TABLE IF NOT EXISTS teams ( id INTEGER , user_id INTEGER , player TEXT NOT NULL,\
            PRIMARY KEY(id),FOREIGN KEY(user_id) REFERENCES users(id))")



@app.route("/")
@login_required
def index():
    return render_template("welcome.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("register.html")

    username = request.form.get("username")
    password = request.form.get("password")
    confirmation = request.form.get("confirmation")

    # check cornercases
    n=len(db.execute('SELECT username FROM users WHERE username = ?', username))
    if username == "" :
        return apology("Invalid Username: Blank, or already exists")
    if n>0:
        return apology("Invalid Username: Blank, or already exists")
    if password == "":
        return apology("Invalid Password: Blank, or does not match")
    if password != confirmation:
        return apology("Invalid Password: Blank, or does not match")


    # Add new user to users database
    hash=generate_password_hash(password)
    db.execute('INSERT INTO users (username, hash) \
            VALUES(?, ?)', username, hash)
    # Query database for username
    rows = db.execute("SELECT * FROM users WHERE username = ?", username)
    # Log user in, i.e. Remember that this user has logged in
    session["user_id"] = rows[0]["id"]
    # Redirect user to home page
    return redirect("/")


@app.route("/players", methods=["GET", "POST"])
@login_required
def players():
    if request.method == "GET":
        return render_template("players.html")
    name1 = request.form.get("name1")
    name2 = request.form.get("name2")
    if name1 == "" :
        return apology("Invalid name: Blank")
    if name2 == "" :
        return apology("Invalid name: Blank")
    dn = SQL("sqlite:///players.db")
    db_INF_name1=dn.execute("SELECT * FROM players WHERE full_name = ?",name1)
    db_INF_name2=dn.execute("SELECT * FROM players WHERE full_name = ?",name2)
    for row in db_INF_name1:
        for row2 in db_INF_name2:
            if row["position"] == row2["position"]:
                     if row["position"] == "Forward":
                        rank1=dn.execute("SELECT rank_in_league_top_attackers FROM players WHERE full_name = ?",name1)[0]['rank_in_league_top_attackers']
                        rank2=dn.execute("SELECT rank_in_league_top_attackers FROM players WHERE full_name = ?",name2)[0]['rank_in_league_top_attackers']
                        if rank1 > rank2 :
                            winner=name1
                        elif rank2>rank1 :
                             winner=name2
                        else:
                            winner="tie"
                     elif row["position"]=="Midfielder":
                        rank1=dn.execute("SELECT rank_in_league_top_midfielders FROM players WHERE full_name = ?",name1)[0]['rank_in_league_top_midfielders']
                        rank2=dn.execute("SELECT rank_in_league_top_midfielders FROM players WHERE full_name = ?",name2)[0]['rank_in_league_top_midfielders']
                        if rank1 > rank2 :
                            winner=name1
                        elif rank2>rank1 :
                             winner=name2
                        else:
                            winner="tie"
                     elif row["position"] =="Defender":
                         rank1=dn.execute("SELECT rank_in_league_top_defenders FROM players WHERE full_name = ?",name1)[0]['rank_in_league_top_defenders']
                         rank2=dn.execute("SELECT rank_in_league_top_defenders FROM players WHERE full_name = ?",name2)[0]['rank_in_league_top_defenders']
                         if rank1 > rank2 :
                             winner=name1.upper()
                         elif rank2>rank1 :
                             winner=name2.upper()
                         else:
                             winner="TIE"

                     return render_template("players2.html",db_INF_name1=db_INF_name1,db_INF_name2=db_INF_name2,winner=winner)

            return render_template("players2.html",db_INF_name1=db_INF_name1,db_INF_name2=db_INF_name2)


@app.route("/players2", methods=["GET", "POST"])
@login_required
def players2():
    if request.method == "GET":
        return render_template("players2.html")

    value = request.form.get('add_player1')
    value2 = request.form.get('add_player2')
    if value:
        db.execute('INSERT INTO teams (user_id, player) \
            VALUES(?, ?)', session["user_id"], value)
    if value2:
        db.execute('INSERT INTO teams (user_id, player) \
            VALUES(?, ?)', session["user_id"], value2)
    return render_template("players2.html")




@app.route("/teams", methods=["GET", "POST"])
@login_required
def teams():
    if request.method == "GET":
        return render_template("teams.html")
    team = request.form.get("team")

    if team == "" :
        return apology("Invalid name: Blank")

    dt = SQL("sqlite:///teams.db")
    teams_db=dt.execute("SELECT * FROM teams WHERE common_name = ?",team)
    return render_template("teams2.html",teams_db=teams_db)



@app.route("/myteam", methods=["GET", "POST"])
@login_required
def team():
    teams=db.execute("SELECT * FROM teams WHERE user_id = ?",session["user_id"])
    if request.method == "GET":
        return render_template("myteam.html",teams=teams)
    return render_template("myteam.html",teams=teams)






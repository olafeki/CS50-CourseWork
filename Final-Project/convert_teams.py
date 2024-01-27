import cs50
import csv

# Create database
open("teams.db", "w").close()
dn = cs50.SQL("sqlite:///teams.db")

# Create tables
dn.execute("CREATE TABLE teams (id  INTEGER,team_name TEXT NOT NULL,common_name TEXT NOT NULL ,season TEXT NOT NULL,country TEXT NOT NULL,matches_played INTEGER,wins INTEGER,draws INTEGER,losses INTEGER,points_per_game INTEGER,league_position INTEGER,performance_rank INTEGR,goals_scored INTEGER,clean_sheets INTEGER)")


with open("teams.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)
    id =0 ;
    # Iterate over CSV file
    for row in reader:

        # Canoncalize title
        team_name = row["team_name"]
        common_name = row["common_name"]
        season = row["season"]
        country = row["country"]
        matches_played = row["matches_played"]
        wins=row["wins"]
        draws=row["draws"]
        losses=row["losses"]
        points_per_game=row["points_per_game"]
        league_position=row["league_position"]
        performance_rank=row["performance_rank"]
        goals_scored=row["goals_scored"]
        clean_sheets=row["clean_sheets"]

        id+=1



        show_id = dn.execute("INSERT INTO teams (id,team_name,common_name,season,country,matches_played,wins,draws,losses,points_per_game,league_position,performance_rank,goals_scored,clean_sheets)VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?)",id,team_name,common_name,season,country,matches_played,wins,draws,losses,points_per_game,league_position,performance_rank,goals_scored,clean_sheets)






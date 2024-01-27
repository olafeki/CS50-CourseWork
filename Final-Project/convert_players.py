import cs50
import csv

# Create database
open("players.db", "w").close()
db = cs50.SQL("sqlite:///players.db")

# Create tables
db.execute("CREATE TABLE players ( id INTEGER ,full_name TEXT NOT NULL ,age INTEGER,birthday INTEGER,birthday_GMT TEXT NOT NULL\
,league TEXT NOT NULL,season TEXT NOT NULL,position TEXT NOT NULL ,Current_Club TEXT NOT NULL\
,minutes_played_overall INTEGER ,minutes_played_home INTEGER ,minutes_played_away INTEGER\
,nationality TEXT NOT NULL\
,appearances_overall INTEGER ,appearances_home INTEGER , appearances_away INTEGER \
,goals_overall INTEGER , goals_home INTEGER ,goals_away INTEGER\
,assists_overall INTEGER ,assists_home INTEGER ,assists_away INTEGER\
,penalty_goals INTEGER ,penalty_misses INTEGER\
, clean_sheets_overall INTEGER ,clean_sheets_home INTEGER ,clean_sheets_away INTEGER\
,conceded_overall INTEGER ,conceded_home INTEGER ,conceded_away INTEGER\
,yellow_cards_overall INTEGER,red_cards_overall INTEGER \
,goals_involved_per_90_overall REAL,assists_per_90_overall REAL\
,goals_per_90_overall REAL,goals_per_90_home REAL,goals_per_90_away REAL \
,min_per_goal_overall REAL\
,conceded_per_90_overall REAL ,min_per_conceded_overall REAL\
,min_per_match REAL,min_per_card_overall REAL,min_per_assist_overall REAL,cards_per_90_overall REAL\
,rank_in_league_top_attackers INTEGER,rank_in_league_top_midfielders INTEGER,rank_in_league_top_defenders INTEGER ,rank_in_club_top_scorer INTEGER)")


# Open CSV file
with open("players.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)
    id =0 ;
    # Iterate over CSV file
    for row in reader:

        # Canoncalize title
        full_name = row["full_name"]
        age = row["age"]
        birthday=row["birthday"]
        birthday_GMT=row["birthday_GMT"]
        league=row["league"]
        season=row["season"]
        position=row["position"]
        Current_Club=row["Current_Club"]
        minutes_played_overall=row["minutes_played_overall"]
        minutes_played_home=row["minutes_played_home"]
        minutes_played_away=row["minutes_played_away"]
        nationality=row["nationality"]
        appearances_overall=row["appearances_overall"]
        appearances_home=row["appearances_home"]
        appearances_away=row["appearances_away"]
        goals_overall=row["goals_overall"]
        goals_home=row["goals_home"]
        goals_away=row["goals_away"]
        assists_overall=row["assists_overall"]
        assists_home=row["assists_home"]
        assists_away=row["assists_away"]
        penalty_goals =row["penalty_goals"]
        penalty_misses=row["penalty_misses"]
        clean_sheets_overall=row["clean_sheets_overall"]
        clean_sheets_home=row["clean_sheets_home"]
        clean_sheets_away=row["clean_sheets_away"]
        conceded_overall=row["conceded_overall"]
        conceded_home=row["conceded_home"]
        conceded_away=row["conceded_away"]
        yellow_cards_overall=row["yellow_cards_overall"]
        red_cards_overall=row["red_cards_overall"]
        goals_involved_per_90_overall=row["goals_involved_per_90_overall"]
        assists_per_90_overall=row["assists_per_90_overall"]
        goals_per_90_overall=row["goals_per_90_overall"]
        goals_per_90_home=row["goals_per_90_home"]
        goals_per_90_away=row["goals_per_90_away"]
        min_per_goal_overall=row["min_per_goal_overall"]
        conceded_per_90_overall=row["conceded_per_90_overall"]
        min_per_conceded_overall=row["min_per_conceded_overall"]
        min_per_match=row["min_per_match"]
        min_per_card_overall=row["min_per_card_overall"]
        min_per_assist_overall=row["min_per_assist_overall"]
        cards_per_90_overall=row["cards_per_90_overall"]
        rank_in_league_top_attackers=row["rank_in_league_top_attackers"]
        rank_in_league_top_midfielders=row["rank_in_league_top_midfielders"]
        rank_in_league_top_defenders=row["rank_in_league_top_defenders"]
        rank_in_club_top_scorer=row["rank_in_club_top_scorer"]
        id+=1
        # Insert title
        show_id = db.execute("INSERT INTO players (id,full_name , age ,birthday,birthday_GMT,league,season,position,Current_Club\
        ,minutes_played_overall,minutes_played_home,minutes_played_away\
        , nationality\
        ,appearances_overall,appearances_home,appearances_away\
        , goals_overall,goals_home,goals_away\
        , assists_overall ,assists_home ,assists_away \
        ,penalty_goals,penalty_misses\
        , clean_sheets_overall,clean_sheets_home  ,clean_sheets_away\
        ,conceded_overall,conceded_home,conceded_away \
        ,yellow_cards_overall,red_cards_overall \
        ,goals_involved_per_90_overall,assists_per_90_overall \
        ,goals_per_90_overall,goals_per_90_home,goals_per_90_away\
        ,min_per_goal_overall,conceded_per_90_overall,min_per_conceded_overall\
        ,min_per_match,min_per_card_overall,min_per_assist_overall,cards_per_90_overall \
        ,rank_in_league_top_attackers,rank_in_league_top_midfielders,rank_in_league_top_defenders,rank_in_club_top_scorer )\
         VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)"\
        , id,full_name,age,birthday,birthday_GMT,league,season,position,Current_Club\
        ,minutes_played_overall,minutes_played_home,minutes_played_away\
        ,nationality\
        ,appearances_overall,appearances_home,appearances_away\
        , goals_overall,goals_home,goals_away\
        ,assists_overall ,assists_home ,assists_away\
        ,penalty_goals,penalty_misses\
        , clean_sheets_overall,clean_sheets_home,clean_sheets_away\
        ,conceded_overall,conceded_home,conceded_away \
        ,yellow_cards_overall,red_cards_overall \
        ,goals_involved_per_90_overall,assists_per_90_overall \
        ,goals_per_90_overall,goals_per_90_home,goals_per_90_away\
        ,min_per_goal_overall,conceded_per_90_overall,min_per_conceded_overall\
        ,min_per_match,min_per_card_overall,min_per_assist_overall,cards_per_90_overall \
        ,rank_in_league_top_attackers,rank_in_league_top_midfielders,rank_in_league_top_defenders,rank_in_club_top_scorer)







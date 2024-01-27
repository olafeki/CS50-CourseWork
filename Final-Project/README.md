# PREMIER_LEAGUE

## CS50
>This was my final project for conclude the CS50 Introduction to Computer Sciense course.

>CS, python, flask, flask web framework, web development, CS50
>I've used Flask web framework based in Python
## Features

- Find the statistics of any player in the Premier League
- Compare the players to choose the best
- Find the statistics of your favorite club in the Premier League
- Create your own team

## Explaining the project and the database
My final project is a website where The user is allowed to view the statistics of clubs and players in the English Premier League
and can also compare between the players.
The program uses the database to show the winner,
and also provides the user the opportunity to form their own team.

All information about users, and each user's team is provided in **users.db**.

All information about players is provided in **players.db**.

All information about teams is provided in **teams.db**.


## Register page
at this page you are abe to make a new account by just entering a name and password and confirming the password and automatically your data is saved in the users.db and  i use the hash funtion to saved the hashed password in the db


## login page
now you can login to the web page by entering your name and password correctly to access your data


## homepage
at this page you have the opportunity to logout , or to start to search the stats you are searching for .
- if you are intersted to know a specific player"s stats , or to compare between 2 players, you choose players from the top
- if you are intersted to see your fav club stats at this year , you choose teams from the top bar .
- if you want to see your own team , you choose my team from the top . how to add players into ? we will see soon .


## players page
by clicking players from the home page , you can type the name of any 2 players  at that specific season (type the name correctly ex:Mohamed Salah,Sadio Mané )  and it will show you their stats , and announce the winner (if they have the same POSITION ), also you ave the option to add any of those player to your team by clicking *on add player 1* or *add player 2* buttons .


## my team page
at this page , the players you added to your team will will be displayed


## teams page
at this page , the user is asked to write his favorite team name , and then the team stats will be displayed.


### sqlite3:
I needed two tables for my database:

- First, table users. Where I put, id, username, hash (for password) , notice that id must be a primary key here.

- Second, table teams. I put user_id, player, Notice that here user_id must be a foreign key.

I USE TWO DATABASE TO EXTRACT PREMIER LEAUGUE STATS FROM :
- first, players.db , to show each player data , and to compare between players .

- second, teams.db, to show each team stats in prem league 2018-2019 .


### Storing each user input in new table.
The input field of images have a single validate, my database have a filename field in a table and I upload this image with flask-wtf extension to my filesystem, then I have to validate each name file for don't overwrite the images with same name.


### converting the csv data files into sqlite 3 tables:
in **convert_players.py** and **convert_teams.py** i wrote an algorithm to read the csv files and convert it into sqlite tables , to use this data in my web application.


### front-end and styling my web page
i create a folder named templates where is stored all the html files for each page in my web page
and another folder named static where my **styles.css** is stored .


## Pictures
- Login and Register page

| Login | Register |
| :---: | :---: |
| <img src="https://img.freepik.com/free-vector/stylish-white-background-with-diagonal-lines_1017-33199.jpg">  | <img src="https://img.freepik.com/free-vector/stylish-white-background-with-diagonal-lines_1017-33199.jpg">|

- Homepage and players

| Homepage | players |
| :---: | :---: |
| <img src="https://wallpaperaccess.com/full/7850968.gif"> | <img src="https://cdn.wallpapersafari.com/91/11/9rcuJ2.jpg">


## Demonstration on youtube
For the CS50 final project you have to make a video showing your project,
[My Final Project presentation](https://youtu.be/2Ey0vIZ8JO0)



## About CS50
CS50 is a openware course from Havard University and taught by David J. Malan

Introduction to the intellectual enterprises of computer science and the art of programming. This course teaches students how to think algorithmically and solve problems efficiently. Topics include abstraction, algorithms, data structures, encapsulation, resource management, security, and software engineering. Languages include C, Python, and SQL plus students’ choice of: HTML, CSS, and JavaScript (for web development).

Thank you for all CS50.

- Where I get CS50 course?
https://cs50.harvard.edu/x/2020/


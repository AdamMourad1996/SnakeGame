# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

## Introduction

I have chosen the Snake Game project as part of my Capstone Project

I have created many different features in this project :-
1. I added small user interface where the user can select 3 options when the game starts
    1. Play a new Game: when the user enters the new game . The user must enter his/her name and select the difficulty of the game. (note the difficulity is based on the  starting speed of the snake).
    2. View the Score Board : When the user selects the view score board, the history of the game is printed out in the terminal and stating out all the player who played the game and they are sorted based on the score for each one.
    3. Exist the game : is simply terminating the code. 
2. I added an option to pause the game while playing by simply press the [p] key on the keyboard
3. To resume the game user should press the [r] key on the keyboard 

## Added Files

I added two classes which are the Player class (Player.h and Player.cpp) and the ScoreBoard Class (ScoreBoard.h and Scoreboard.cpp)
1. The Player class is responsible to encapsulate data from the user and these data will be passed and used in rest of the program
2. The ScoreBoard class is responsible to read, write, and update from file called ScoreBoard.txt file which contains the hsitory borad and sort the data inside the file based on the highest score 

## Rubic Points

I have tried my best to add as many points as I can and I ended up adding these points :-

Loop, Function, I/O
  1. The project demonstrates an understanding of C++ functions and control structures.
  2. The project reads data from a file and process the data, or the program writes data to a file.
  3. The project accepts user input and processes the input.

Object Oriented Programming

  1. The project uses Object Oriented Programming techniques.
  2. Classes use appropriate access specifiers for class members.
  3. Class constructors utilize member initialization lists.
  4. Classes abstract implementation details from their interfaces.
  5. Classes encapsulate behavior.

Memory Management

  1. The project makes use of references in function declarations.
  2. The project uses move semantics to move data, instead of copying it, where possible. (In the main function in Inserting in player function line 108)
  3. The project uses smart pointers instead of raw pointers.


Files that I have coded inside are 

  1. main.cpp
  2. game.cpp & game.h
  3. Player.cpp & Player.h
  4. ScoreBoard.cpp & ScoreBoard.h
  5. controller.cpp & controller.h



## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.
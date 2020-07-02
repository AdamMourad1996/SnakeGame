//include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <string>


int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  /*Declaring the input variables */
  char UserOption, Difficulty ;
  std::string UserName, UserDifficulty;
  float InitialSpeed;
  bool PlayGame, ViewScoreBoard =false;

  /*Creating an opening for the game as the user can select different options*/
  std::cout<< "******* Welcome to the SnakeGame  *******" << "\n";
  std::cout<< "LETS GO and Do not waste time and select one of the following options by typing the number crossponding to it  !!!!" << "\n";
  std::cout<< "1. Start a new game " << "\n";
  std::cout<< "2. Score Board  " << "\n";
  std::cout<< "3. Exist " << "\n";
  std::cin>>UserOption;

  /*Creating a Scoreboard object which contain the score and the hsitory of the players*/
  ScoreBoard board;

  /*As starting the game, must laod all the history data so in the future the program can comapre between new data with old data 
    and figure out the highest score of them all */
  board.LoadFromFile();

  switch (UserOption)
  {
    case '1': // the User slected to play a game
    PlayGame = true;
    std::cout<< "******* Way To Goo*******" << "\n";
    std::cout<< "******* Please Enter Your name *******" << "\n";
    std::cin>>UserName;
    std::cout<< "******* Please select the difficulty level *******" << "\n";
    std::cout<< "1. Easy       2. Intermediate       3. Hard" << "\n";
    std::cin>>Difficulty;
    std::cout<< "*******GoodLuck " << UserName <<"*******"<<"\n";
    std::cout<< "Try your best to beat our friend " <<board.GetHighestScore().getName() << " Who scored the highest score "<< board.GetHighestScore().getScore()<<"\n";


    /*I added a new feature which the user can select the difficulty of the game mode 
    by selecting one of the three options the speed of the snake will be varied crosspondingly */
    switch (Difficulty)
    {
      case '1': 
      InitialSpeed = 0.1;
      UserDifficulty ="Easy";
      break;
      case '2': 
      InitialSpeed = 0.3;
      UserDifficulty ="Intermediate";
      break;
      case '3': 
      InitialSpeed = 0.5;
      UserDifficulty ="Hard";
      break;
    }

    break;
   
    case '2': // the user wants to see the Score Board history
    ViewScoreBoard =true;

    break;
   
    case '3':
    std::cout<< "******* User quit the SnakeGame :( *******" << "\n";
    break;

  }

    if(ViewScoreBoard)
    {
     board.PrintFile();

    }
    else
    {
      if(PlayGame)
      {
      Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
      Controller controller;
      Game game(kGridWidth, kGridHeight);

      /*Created a Player object which contain data about the player*/
      Player player (UserName,UserDifficulty,InitialSpeed);
      
      /*Then the player is passed by referenece to the game run */
      game.Run(controller, renderer, kMsPerFrame, player);

    
      std::cout << "Game has terminated successfully!\n";
      std::cout << "Score: " << game.GetScore() << "\n";
      std::cout << "Size: " << game.GetSize() << "\n";

      /*After finishing th game the player will be inserted to the ScoreBoard 
      and Update the board to save the data for necxt time*/
      board.InsertPlayer(std::move(player));
      board.UpdateFile();
      }
    }

  return 0;
}
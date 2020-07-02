#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "Player.h"
#include <memory>
#include <vector>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

/*Path for the ScoreBoard File */
const std::string ScoreBoardFile{"ScoreBoard.txt"};


/*ScoreBoard class is responsible to save data, wirte data, and sort the datta*/
class ScoreBoard
{
    public:
    ~ScoreBoard(){};
    
    void LoadFromFile();
    void PrintFile();
    void InsertPlayer (Player &&p);
    Player GetHighestScore ();
    void UpdateFile ();



    private:
    /*Saving the data from the file in a vector of unique pointers */
    std::vector<std::unique_ptr<Player>> m_players;
    void SortPlayers();

};

#endif
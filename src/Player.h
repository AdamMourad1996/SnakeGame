#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>


/*This Player class contains data the is related to user and will be used to store it in the Score board*/

class Player
{
    public:
    Player(){};
    Player (std::string name, std::string difficulty, float speed);
    Player (std::string name,int score, std::string difficulty);
    ~Player();

    /*Getters Function*/
    std::string getName() const  {return m_name;}
    std::string getDifficulty() const  {return m_difficulty;}
    int getScore() const {return m_score;}
    float getSpeed() const {return m_speed;}

    /*Setters Function*/
    void setScore(int value) {m_score = value;}

    private:
    std::string m_name;
    std::string m_difficulty;
    float m_speed;
    int m_score;


    
};

#endif
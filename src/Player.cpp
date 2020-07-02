#include "Player.h"



Player::Player(std::string name,int score, std::string difficulty):
    m_name(name),
    m_difficulty(difficulty),
    m_score(score),
    m_speed(0)
    {}

Player::Player(std::string name,std::string difficulty, float speed):
    m_name(name),
    m_difficulty(difficulty),
    m_speed(speed),
    m_score(0)
    {}

    Player::~Player(){}
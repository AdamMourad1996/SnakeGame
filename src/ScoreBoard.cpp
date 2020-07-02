#include "ScoreBoard.h"

/*Function to sort the list based on the score of the player*/
static bool SortOnScore(std::unique_ptr<Player> &p1, std::unique_ptr<Player> &p2)
{
return p1->getScore() > p2->getScore() ;
}


void ScoreBoard::SortPlayers()
{
    sort(m_players.begin(),m_players.end(),SortOnScore);

}


void ScoreBoard::InsertPlayer (Player &&p)
{
    m_players.emplace_back(std::make_unique<Player>(p.getName(), p.getScore(), p.getDifficulty()));
    SortPlayers();

}

Player ScoreBoard::GetHighestScore ()
{
    SortPlayers();
    return *(m_players.front().get());
}



void ScoreBoard::LoadFromFile ()
{
  std::string line;
  std::string index;
  std::string name;  
  std::string score;
  std::string difficulty;

  std::ifstream filestream(ScoreBoardFile);
  if (filestream.is_open()) {
    std::getline(filestream, line);
    std::getline(filestream, line);
    std::getline(filestream, line);
    std::getline(filestream, line);
    std::getline(filestream, line);

    while (std::getline(filestream, line)) 
        {
        std::istringstream linestream(line);
        while(linestream>>index>>name>>score>>difficulty){
        m_players.emplace_back(std::make_unique<Player>(name, std::stoi(score), difficulty));
        
        
        }      
    }
  }
}

void ScoreBoard::PrintFile ()
{
  std::string line;
  std::string index;
  std::string name;  
  std::string score;
  std::string difficulty;

  int count =5;
  std::ifstream filestream(ScoreBoardFile);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
        std::cout<<line<<"\n";
        }
       
    }      
    
}

void ScoreBoard::UpdateFile()
{
      std::ofstream scoreboard (ScoreBoardFile);
      if(scoreboard.is_open())
      {
        scoreboard << "************************************************************ \n";
        scoreboard << "******************Top Scores in the Snake game************** \n";
        scoreboard << "************************************************************ \n";
        scoreboard << "\n";
        scoreboard << "Here is the lsit of the top scores :- \n";
        int index =1;
        for(auto& p: m_players)
        {
            scoreboard<<index << " "<< p->getName()<< " "<< p->getScore()<<" "<<p->getDifficulty();
            scoreboard << "\n";
            index++;
        }

        scoreboard.close();
      }
      
}

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller {
 public:
  void HandleInput(bool &running, Snake &snake) const;

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;

  /*Pause function is used to pause the game by pressing the p key on the keyboard while 
  and then can resume the game by pressing the (r) key */
  void PuaseGame () const;


};

#endif

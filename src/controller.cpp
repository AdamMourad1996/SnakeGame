#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}
void Controller::PuaseGame () const
{          
  std::cout<<"The game is paused !!!"<<"\n";
  std::cout<<"To resume the game please press the (r) key  "<<"\n";
  std::cout<<"*****************"<<"\n";
  SDL_Event f;
  bool t=true;
      while (t) {  
        if(SDL_PollEvent(&f)){
        if(f.key.keysym.sym ==SDLK_r)
          {
            t=false;
            std::cout<<"Back to the game :) "<<"\n";
            return;
          }
        }
  }
}

void Controller::HandleInput(bool &running, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
        
        /* whenever the user press on the p key on the keyboard 
           the game pauses */
        case SDLK_p: 
          PuaseGame();
          break;
        
        case SDLK_q:
          std::cout<<"User left the game :("<<"\n";
          running = false;
          break;
      }
    }
  }
}
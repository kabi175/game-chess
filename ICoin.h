#include <SDL2/SDL.h>
#pragma once
class ICoin {
public:
  virtual bool verify(int, int) = 0;
  virtual void render(SDL_Renderer *) = 0;
  virtual void move(int, int) = 0;
};

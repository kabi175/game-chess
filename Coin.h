#pragma once
#include "ICoin.h"
#include <SDL2/SDL.h>

enum class COLOR { WHITE, BLACK, NONE };
enum class TYPE { KING, QUEEEN };

class Coin : public ICoin {
private:
  int row, col;
  SDL_Texture *image;
  COLOR color;
  TYPE type;

public:
  Coin(SDL_Renderer *, COLOR, TYPE, int, int);
  ~Coin();
  void render(SDL_Renderer *ren);
  void move(int, int);
  bool verify(int, int);
};

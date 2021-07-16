#pragma once
#include "Coin.h"
#include "ICoin.h"
#include <SDL2/SDL.h>

class Board {
private:
  SDL_Renderer *renderer;
  Board(SDL_Renderer *);
  ICoin *board[8][8];

public:
  static Board *getInstance(SDL_Renderer *);
  ~Board();
  void render();
  void handleClick(int row, int col);
};

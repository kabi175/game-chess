#include "Board.h"

Board::Board(SDL_Renderer *ren) { renderer = ren; }

Board::~Board() {}

void Board::render() {
  SDL_Rect dest;
  dest.w = 70;
  dest.h = 70;
  SDL_SetRenderDrawColor(renderer, 45, 25, 55, 255);
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      if (row % 2 == 0) {
        if (col % 2 == 0) {
          // white
          SDL_SetRenderDrawColor(renderer, 212, 180, 169, 255);
        } else {
          // black
          SDL_SetRenderDrawColor(renderer, 128, 122, 120, 255);
        }
      } else {
        if (col % 2 != 0) {
          SDL_SetRenderDrawColor(renderer, 212, 180, 169, 255);
          // white
        } else {
          // black
          SDL_SetRenderDrawColor(renderer, 128, 122, 120, 255);
        }
      }
      dest.x = 70 * col;
      dest.y = 70 * row;
      SDL_RenderFillRect(renderer, &dest);
    }
  }
}

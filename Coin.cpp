#include "Coin.h"
#include "TextureManager.h"
#include <string>

Coin::Coin(SDL_Renderer *ren, COLOR color_, TYPE type_, int row_, int col_)
    : ICoin() {
  row = row_;
  col = col_;
  color = color_;
  type = type_;
  std::string file = "assest/bK.png";
  image = TextureManager::loadImage(ren, file);
}

Coin::~Coin() { TextureManager::destroyImage(image); }

void Coin::render(SDL_Renderer *ren) {
  SDL_Rect rect;

  rect.x = 60 * col;
  rect.y = 60 * row;
  rect.w = 60;
  rect.h = 60;

  SDL_RenderCopy(ren, image, NULL, &rect);
}

void Coin::move(int row_, int col_) {
  row = row_;
  col = col_;
}

bool Coin::verify(int x, int y) { return true; }

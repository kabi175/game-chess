#include "TextureManager.h"

SDL_Texture *TextureManager::loadImage(SDL_Renderer *ren, std::string file) {
  SDL_Texture *tex = IMG_LoadTexture(ren, file.c_str());

  if (tex == NULL) {
    printf("Error: %s", SDL_GetError());
  }

  return tex;
}

void TextureManager::destroyImage(SDL_Texture *tex) { SDL_DestroyTexture(tex); }

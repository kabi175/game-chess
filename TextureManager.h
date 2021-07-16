#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class TextureManager {
public:
  static SDL_Texture *loadImage(SDL_Renderer *, std::string);
  static void destroyImage(SDL_Texture *);
};

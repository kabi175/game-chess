#include <SDL2/SDL.h>

class Board {
private:
  SDL_Renderer *renderer;

public:
  Board(SDL_Renderer *);
  ~Board();
  void render();
};

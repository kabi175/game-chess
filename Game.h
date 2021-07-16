#include <SDL2/SDL.h>
#include <string>

class Game {
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool quit;
  void handleError();

public:
  Game(std::string, int, int);
  ~Game();
  bool isRunning();
  void handleEvents();
  void update();
  void render();
};

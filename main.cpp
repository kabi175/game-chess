#include "Game.h"

char TITLE[] = "Chess";
const int WIDTH = 70 * 8;
const int HEIGHT = 70 * 8;

int main() {
  Game game = Game(TITLE, WIDTH, HEIGHT);
  while (game.isRunning()) {
    game.handleEvents();
    game.update();
    game.render();
  }
}

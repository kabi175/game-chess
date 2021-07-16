#include "Game.h"
#include "Board.h"

Game::Game(std::string title, int width, int height) {
  quit = false;
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1) {
    handleError();
    return;
  }
  window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, width, height, 0);
  if (window == NULL) {
    handleError();
    return;
  }

  renderer = SDL_CreateRenderer(window, 0, -1);
}

Game::~Game() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

bool Game::isRunning() { return !quit; }

void Game::handleError() {
  printf("Error: %s\n", SDL_GetError());
  quit = true;
}

void Game::handleEvents() {
  SDL_Event events;
  while (SDL_PollEvent(&events)) {
    switch (events.type) {
    case SDL_QUIT:
      quit = true;
      break;
    }
  }
}

void Game::render() {
  SDL_RenderPresent(renderer);
  SDL_RenderClear(renderer);
}

void Game::update() {
  static Board board = Board(renderer);
  board.render();
}

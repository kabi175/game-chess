#include "Board.h"

char init[8][8][3] = {
    {
        "WE",
        "WH",
        "WB",
        "WQ",
        "WK",
        "WB",
        "WH",
        "WE",
    },
    {
        "WP",
        "WP",
        "WP",
        "WP",
        "WP",
        "WP",
        "WP",
        "WP",
    },
    {
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
    },
    {
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
    },
    {
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
    },
    {
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
    },
    {
        "BP",
        "BP",
        "BP",
        "BP",
        "BP",
        "BP",
        "BP",
        "BP",
    },
    {
        "BE",
        "BH",
        "BB",
        "BQ",
        "BK",
        "BB",
        "BH",
        "BE",
    },
};

Board *Board::getInstance(SDL_Renderer *ren) {
  static Board *instance = new Board(ren);
  return instance;
}

Board::Board(SDL_Renderer *ren) {
  renderer = ren;
  board[4][4] = new Coin(ren, COLOR::BLACK, TYPE::KING, 4, 4);
}

Board::~Board() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      if (board[row][col] != NULL) {
        free(board[row][col]);
      }
    }
  }
}

void Board::render() {
  SDL_Rect dest;
  dest.w = 60;
  dest.h = 60;
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
      dest.x = 60 * col;
      dest.y = 60 * row;
      SDL_RenderFillRect(renderer, &dest);
    }
  }

  board[4][4]->render(renderer);
  return;
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      if (board[row][col]) {
        board[row][col]->render(renderer);
      }
    }
  }
}

void Board::handleClick(int row, int col) {
  static ICoin *selected = NULL;
  if (board[row][col] == NULL)
    return;
  if (selected == NULL) {
    selected = board[row][col];
    return;
  }
  if (selected->verify(row, col)) {
    selected->move(row, col);
    board[row][col] = selected;
    selected = NULL;
  }
  return;
}

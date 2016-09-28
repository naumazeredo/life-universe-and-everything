/**
  Life, the Universe and Everything
 */
#include "game.h"

const std::string title = "Life, the Universe and Everything";

int main() {
  Game& game = Game::getInstance();
  game.start(title, 800, 600);

  return 0;
}

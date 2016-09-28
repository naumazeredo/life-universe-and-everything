/**
  Life, the Universe and Everything
 */
#include "game.h"

const std::string title = "Life, the Universe and Everything";

int main() {
  Game game(title, 800, 600);
  game.run();

  return 0;
}

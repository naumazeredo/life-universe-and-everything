/**
  Life, the Universe and Everything
 */
#include "game.h"
#include "version.h"

const std::string title = "Life, the Universe and Everything - " + VERSION;

int main() {
  Game::start(title, 1024, 768);
  Game::run();
  Game::destroy();

  return 0;
}

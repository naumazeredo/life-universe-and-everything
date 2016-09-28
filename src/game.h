/**
  game.h
 */

#pragma once

#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Game {
public:
  Game(const std::string&, int, int);
  ~Game();

  void run();

  inline SDL_Window*   window()   { return window_; }
  inline SDL_Renderer* renderer() { return renderer_; }

private:
  SDL_Window*   window_;
  SDL_Renderer* renderer_;
};

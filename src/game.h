/**
  game.h
 */

#pragma once

#include <string>

struct SDL_Window;
struct SDL_Renderer;

namespace Game {

void run(const std::string&, int, int);

// TODO: don't pass these pointers!
//SDL_Window*   getWindow();
SDL_Renderer* getRenderer();
};

/**
  game.h
 */

#pragma once

#include <string>

struct SDL_Window;
struct SDL_Renderer;

namespace Game {

void start(const std::string&, int, int);
void destroy();

void run();

// TODO: don't pass these pointers!
//SDL_Window*   getWindow();
SDL_Renderer* getRenderer();
};

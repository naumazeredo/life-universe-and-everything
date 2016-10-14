/**
  game.h
 */

#pragma once

#include <string>
#include "util/types.h"

struct SDL_Window;
struct SDL_Renderer;

namespace Game {

void start(const std::string&, int, int);
void destroy();

void run();

Vec2 getWindowSize();
void setDrawColor(Color);
void drawLine(Vec2, Vec2);
void drawRect(Rect);

// TODO: don't pass these pointers!
//SDL_Window*   getWindow();
SDL_Renderer* getRenderer();

}

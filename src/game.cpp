/**
  game.cpp
 */
#include "game.h"

#include <SDL2/SDL.h>
#include "util/types.h"
#include "texturemanager.h"
#include "fontmanager.h"
#include "mouse.h"
#include "keyboard.h"
#include "sprite.h"
#include "button.h"
#include "hangar.h"

namespace Game {

namespace {
  void loadContent() {
    Hangar::start();
  }

  void logic() {}

  SDL_Window*   window_   = nullptr;
  SDL_Renderer* renderer_ = nullptr;
}

//SDL_Window*   getWindow()   { return window_; }
SDL_Renderer* getRenderer() { return renderer_; }

void
start(const std::string& name, int w, int h) {
  // TODO: error checking
  SDL_Init(SDL_INIT_VIDEO);

  window_ = SDL_CreateWindow(
    name.c_str(),
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    w, h,
    0
  );

  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);

  SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_BLEND);
}

void
destroy() {
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
  SDL_Quit();

  renderer_ = nullptr;
  window_   = nullptr;
}

void
run() {
  loadContent();

  u32 lastTime = SDL_GetTicks();

  SDL_Event event;
  while (1) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        return;
      }
    }

    Keyboard::update();
    Mouse::update();

    Hangar::update();

    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0);
    SDL_RenderClear(renderer_);
    logic();
    Hangar::draw();
    SDL_RenderPresent(renderer_);

    // Framelimit
    u32 currentTime = SDL_GetTicks();
    if (currentTime - lastTime < 1000 / 60) {
      auto delay = 1000 / 60 - (currentTime - lastTime);
      SDL_Delay(delay);
    }
    lastTime = currentTime;
  }
}

Vec2
getWindowSize() {
  Vec2 size;
  SDL_GetWindowSize(window_, &size.x, &size.y);
  return size;
}

void
setDrawColor(Color color) {
  SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
}

void
drawLine(Vec2 p1, Vec2 p2) {
  SDL_RenderDrawLine(renderer_, p1.x, p1.y, p2.x, p2.y);
}

void
drawRect(Rect rect) {
  SDL_RenderFillRect(renderer_, &rect);
}

}

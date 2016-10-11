/**
  game.cpp
 */
#include "game.h"

#include <SDL2/SDL.h>
#include "util/types.h"
#include "texturemanager.h"
#include "fontmanager.h"
#include "sprite.h"
#include "button.h"

namespace Game {

namespace {
  void loop();
  void loadContent();
  void logic();

  SDL_Window*   window_   = nullptr;
  SDL_Renderer* renderer_ = nullptr;
}

//SDL_Window*   getWindow()   { return window_; }
SDL_Renderer* getRenderer() { return renderer_; }

void
run(const std::string& name, int w, int h) {
  // TODO: error checking
  SDL_Init(SDL_INIT_VIDEO);

  window_ = SDL_CreateWindow(
    name.c_str(),
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    w, h,
    0
  );

  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);

  // Run game
  loop();

  // Destroy
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
  SDL_Quit();

  renderer_ = nullptr;
  window_   = nullptr;
}

namespace {

void
loop() {
  loadContent();

  u32 lastTime = SDL_GetTicks();

  SDL_Event event;
  while (1) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        return;
      }
    }

    SDL_RenderClear(renderer_);
    logic();
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

void
loadContent() {
}

void
logic() {
}

}

}

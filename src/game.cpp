/**
  game.cpp
 */

#include <cstdio>
#include <SDL2/SDL.h>
#include "game.h"

Game::
Game(const std::string& name, int w, int h) {
  // TODO: log error
  SDL_Init(SDL_INIT_VIDEO);

  window_ = SDL_CreateWindow(
    name.c_str(),
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    w, h,
    0
    //SDL_WINDOW_OPENGL
  );

  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
}

Game::
~Game() {
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

void Game::
run() {
  SDL_Event event;

  while (1) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        return;
      }
    }

    SDL_RenderClear(renderer_);
    SDL_RenderPresent(renderer_);
  }
}

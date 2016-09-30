/**
  game.cpp
 */
#include "game.h"

#include <SDL2/SDL.h>
#include "util/types.h"
#include "texturemanager.h"
#include "fontmanager.h"

void Game::
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

  // Run game
  loop();
}

Game::
Game() :
    window_(nullptr), renderer_(nullptr),
    textureManager_(TextureManager::getInstance()),
    fontManager_(FontManager::getInstance())
{}

Game::
~Game() {
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
  SDL_Quit();

  renderer_ = nullptr;
  window_   = nullptr;
}

void Game::
loop() {
  Font font = fontManager_.loadFont(30);
  Texture text;
  text.loadFromText("Text", font);

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
    text.draw(10, 10);
    SDL_RenderPresent(renderer_);

    // Framelimit
    u32 currentTime = SDL_GetTicks();
    if (currentTime - lastTime < 1000 / 60) {
      SDL_Delay(1000 / 60 - (currentTime - lastTime));
      lastTime = currentTime;
    }
  }
}

void Game::
logic() {
}


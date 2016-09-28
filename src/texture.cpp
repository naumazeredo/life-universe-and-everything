/**
  texture.cpp
 */
#include "texture.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.h"

Texture::
Texture() : texture_(nullptr)
{}

Texture::
Texture(const std::string& path) : Texture() {
  load(path);
}

void Texture::
load(const std::string& path) {
  destroy();

  // TODO: error checking
  SDL_Surface* surface = IMG_Load(path.c_str());

  texture_ = SDL_CreateTextureFromSurface(Game::getInstance().getRenderer(), surface);

  width_   = surface->w;
  height_  = surface->h;

  SDL_FreeSurface(surface);
}

void Texture::
destroy() {
  SDL_DestroyTexture(texture_);
  texture_ = nullptr;
}

void Texture::
draw(int x, int y) const {
  draw(x, y, width_, height_);
}

void Texture::
draw(int x, int y, int w, int h) const {
  if (!texture_)
    return;
  SDL_Rect dest { x, y, w, h};
  SDL_RenderCopy(Game::getInstance().getRenderer(), texture_, nullptr, &dest);
}

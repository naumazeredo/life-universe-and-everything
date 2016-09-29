/**
  texture.cpp
 */
#include "texture.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "game.h"
#include "font.h"

Texture::
Texture(const std::string& path) : Texture() {
  load(path);
}

void Texture::
load(const std::string& path) {
  destroy();

  // TODO: error checking
  SDL_Surface* surface = IMG_Load(path.c_str());

  if (!surface) {
    // TODO: log error correctly
    printf("Could not find image %s: %s\n", path.c_str(), IMG_GetError());
    return;
  }

  texture_ = SDL_CreateTextureFromSurface(Game::getInstance().getRenderer(), surface);
  width_   = surface->w;
  height_  = surface->h;

  SDL_FreeSurface(surface);
}

void Texture::
loadFromText(const std::string& text, const Font& font) {
  destroy();

  // TODO: error checking
  SDL_Surface* surface = TTF_RenderText_Solid(font.getFont(), text.c_str(), {255,255,255,255});

  if (!surface) {
    // TODO: log error correctly
    printf("Could not render text: %s\n", TTF_GetError());
    return;
  }

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

/**
  font.cpp
 */
#include "font.h"

#include <SDL2/SDL_ttf.h>

Font::
Font(/*const std::string& path,*/ int size) {
  load(/*path,*/ size);
}

void Font::
load(/*const std::string& path,*/ int size) {
  // TODO: error checking
  //font_ = TTF_OpenFont(path.c_str(), size);
  font_ = TTF_OpenFont("assets/fonts/Habbo.ttf", size);

  if (!font_) {
    // TODO: log error correctly
    printf("Error while opening font: %s\n", TTF_GetError());
    return;
  }

  size_ = size;
}

void Font::
destroy() {
  TTF_CloseFont(font_);
}

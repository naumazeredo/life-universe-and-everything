/**
  fontmanager.cpp
 */
#include "fontmanager.h"

#include <SDL2/SDL_ttf.h>

FontManager::
FontManager() {
  // TODO: error checking
  TTF_Init();
}

FontManager::
~FontManager() {
  TTF_Quit();
}

Font FontManager::
loadFont(/*const std::string& path,*/ int size) {
  auto font = fonts_.find(size);
  if (font != fonts_.end()) {
    return font->second;
  }

  fonts_.emplace(size, size);
  return fonts_[size];
}

void FontManager::
destroyAllFonts() {
  for (auto& font : fonts_)
    font.second.destroy();
  fonts_.clear();
}

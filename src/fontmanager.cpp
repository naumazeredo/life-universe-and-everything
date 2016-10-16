/**
  fontmanager.cpp
 */
#include "fontmanager.h"

#include <SDL2/SDL_ttf.h>

namespace FontManager {

// Internals
namespace {

std::map<int, Font> fonts_;

}

void
start() {
  // TODO: error checking
  TTF_Init();
}

void
destroy() {
  destroyAllFonts();
  TTF_Quit();
}

Font
loadFont(/*const std::string& path,*/ int size) {
  auto font = fonts_.find(size);
  if (font != fonts_.end()) {
    return font->second;
  }

  fonts_.emplace(size, size);
  return fonts_[size];
}

void
destroyAllFonts() {
  for (auto& font : fonts_)
    font.second.destroy();
  fonts_.clear();
}

}

/**
  font.h

  TODO: allow custom font
 */
#pragma once

#include <string>
#include <SDL2/SDL_ttf.h>

class Font {
public:
  Font() = default;
  Font(/*const std::string&,*/ int);

  void load(/*const std::string&,*/ int);
  void destroy();

  inline TTF_Font* getFont() const { return font_; }
  inline int getSize()       const { return size_; }
private:
  TTF_Font* font_ = nullptr;
  int size_;
};

/**
  texture.h
 */

#pragma once

#include <string>

struct SDL_Texture;
class TextureManager;
class Font;

class Texture {
public:
  Texture() = default;
  Texture(const std::string&);

  void load(const std::string&);
  void loadFromText(const std::string&, const Font&);
  void destroy();

  void draw(int, int) const;
  void draw(int, int, int, int) const;
  //void drawFrame();

  inline int getWidth() const  { return width_; }
  inline int getHeight() const { return height_; }

private:
  SDL_Texture* texture_ = nullptr;
  int width_, height_;
};

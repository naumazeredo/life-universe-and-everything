/**
  texture.h
 */

#pragma once

#include <string>
#include "util/types.h"

struct SDL_Texture;
class Font;

class Texture {
public:
  Texture() = default;
  explicit Texture(const std::string&);
  Texture(const std::string&, const Font&);

  void load(const std::string&);
  void loadFromText(const std::string&, const Font&);
  void destroy();

  void draw(int, int) const;
  void draw(Vec2) const;
  void draw(Rect) const;
  void drawClip(int, int, Rect) const;
  void drawClip(Vec2, Rect) const;
  void drawClip(Rect, Rect) const;

  inline int getWidth() const  { return width_; }
  inline int getHeight() const { return height_; }
  inline Rect getClip() const  { return { 0, 0, width_, height_ }; }

private:
  SDL_Texture* texture_ = nullptr;
  int width_, height_;
};

/**
  sprite.h
 */
#pragma once

#include <string>
#include "texture.h"
#include "util/types.h"

class Sprite {
public:
  Sprite() = default;
  Sprite(const std::string&);
  Sprite(const std::string&, Vec2f);
  Sprite(const std::string&, Rect);
  Sprite(const std::string&, Vec2f, Rect);
  Sprite(Texture);
  Sprite(Texture, Vec2f);
  Sprite(Texture, Rect);
  Sprite(Texture, Vec2f, Rect);

  inline Texture getTexture() const { return texture_; }
  inline Vec2f getSize() const      { return size_; }
  inline Rect getClip() const       { return clip_; }

  void setTexture(Texture);
  inline void setSize(Vec2f size)     { size_ = size; }
  inline void setClip(Rect clip)      { clip_ = clip; }

  void draw(int, int);
  void draw(Vec2);

private:
  Texture texture_;

  Vec2f size_ = { 0.0f, 0.0f };
  Rect clip_  = { 0, 0, 0, 0 };
};

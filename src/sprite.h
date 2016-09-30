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
  Sprite(const std::string&, Rectf);
  Sprite(const std::string&, Rectf, Rect);
  Sprite(Texture);
  Sprite(Texture, Rectf);
  Sprite(Texture, Rectf, Rect);

  inline Texture getTexture() const { return texture_; }
  inline Vec2f getPos() const       { return { dest_.x, dest_.y }; }
  inline Vec2f getSize() const      { return { dest_.w, dest_.h }; }
  inline Rectf getDestRect() const  { return dest_; }
  inline Rect getClip() const       { return clip_; }

  void setTexture(Texture);
  inline void setPos(Vec2f pos)       { dest_.x = pos.x; dest_.y = pos.y; }
  inline void setSize(Vec2f size)     { dest_.w = size.x; dest_.h = size.y; }
  inline void setDestRect(Rectf dest) { dest_ = dest; }
  inline void setClip(Rect clip)      { clip_ = clip; }

  void draw();

private:
  Texture texture_;

  Rectf dest_ = { 0.f, 0.f, 0.f, 0.f };
  Rect  clip_ = { 0, 0, 0, 0 };
};

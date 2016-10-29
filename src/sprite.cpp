/**
  sprite.cpp
 */
#include "sprite.h"
#include "game.h"

Sprite::
Sprite(const std::string& path) {
  setTexture(path);
  auto clip = texture_.getClip();
  size_ = { static_cast<float>(clip.w), static_cast<float>(clip.h) };
}

Sprite::
Sprite(const std::string& path, Rect clip) {
  setTexture(path);
  size_ = { (float)clip.w, (float)clip.h };
  clip_ = clip;
}

Sprite::
Sprite(const std::string& path, Anchor pivot, Anchor anchor) : Sprite(path) {
  setPivot(pivot);
  setAnchor(anchor);
}

Sprite::
Sprite(const std::string& path, Rect clip, Anchor pivot, Anchor anchor) : Sprite(path, clip) {
  setPivot(pivot);
  setAnchor(anchor);
}

Sprite::
Sprite(const std::string& path, Rect clip, Vec2f pos, Anchor pivot, Anchor anchor)
    : Sprite(path, clip, pivot, anchor) {
  setPosition(pos);
}

/*
Sprite::
Sprite(const std::string& path, Vec2f size) {
  setTexture(path);
  size_ = size;
}

Sprite::
Sprite(const std::string& path, Vec2f size, Rect clip) : Sprite(path, size) {
  clip_ = clip;
}

Sprite::
Sprite(Texture texture) {
  setTexture(texture);
  auto clip = texture_.getClip();
  size_ = { static_cast<float>(clip.w), static_cast<float>(clip.h) };
}

Sprite::
Sprite(Texture texture, Vec2f size) {
  setTexture(texture);
  size_ = size;
}

Sprite::
Sprite(Texture texture, Rect clip) {
  setTexture(texture);
  size_ = { (float)clip.w, (float)clip.h };
  clip_ = clip;
}

Sprite::
Sprite(Texture texture, Vec2f size, Rect clip) : Sprite(texture, size) {
  clip_ = clip;
}
*/

void Sprite::
setTexture(Texture texture) {
  texture_ = texture;
  clip_ = { 0, 0, texture_.getWidth(), texture_.getHeight() };
}

Rect Sprite::
getDrawRect () const {
  Rectf dest {
    position_.x - pivot_.x,
    position_.y - pivot_.y,
    static_cast<float>(size_.x),
    static_cast<float>(size_.y)
  };

  const Vec2 windowSize = Game::getWindowSize();

  if      (anchor_.h == HorizontalAnchor::Center) dest.x += windowSize.x/2;
  else if (anchor_.h == HorizontalAnchor::Right)  dest.x += windowSize.x;

  if      (anchor_.v == VerticalAnchor::Center) dest.y += windowSize.y/2;
  else if (anchor_.v == VerticalAnchor::Bottom) dest.y += windowSize.y;

  return dest;
}

void Sprite::
draw() {
  draw(position_);
}

void Sprite::
draw(Vec2 pos) {
  Rect dest {
    pos.x - pivot_.x, pos.y - pivot_.y,
    static_cast<int>(size_.x), static_cast<int>(size_.y)
  };

  const Vec2 windowSize = Game::getWindowSize();

  if      (anchor_.h == HorizontalAnchor::Center) dest.x += windowSize.x/2;
  else if (anchor_.h == HorizontalAnchor::Right)  dest.x += windowSize.x;

  if      (anchor_.v == VerticalAnchor::Center) dest.y += windowSize.y/2;
  else if (anchor_.v == VerticalAnchor::Bottom) dest.y += windowSize.y;

  texture_.drawClip(dest, clip_);
}

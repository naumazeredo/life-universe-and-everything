/**
  sprite.cpp
 */
#include "sprite.h"

Sprite::
Sprite(const std::string& path) {
  setTexture(path);
}

Sprite::
Sprite(const std::string& path, Vec2f size) : Sprite(path) {
  size_ = size;
}

Sprite::
Sprite(const std::string& path, Vec2f size, Rect clip) : Sprite(path, size) {
  clip_ = clip;
}

Sprite::
Sprite(Texture texture) {
  setTexture(texture);
}

Sprite::
Sprite(Texture texture, Vec2f size) : Sprite(texture) {
  size_ = size;
}

Sprite::
Sprite(Texture texture, Vec2f size, Rect clip) : Sprite(texture, size) {
  clip_ = clip;
}

void Sprite::
setTexture(Texture texture) {
  texture_ = texture;
  clip_ = { 0, 0, texture_.getWidth(), texture_.getHeight() };
}

void Sprite::
draw(int x, int y) {
  Rect dest { x, y, static_cast<int>(size_.x), static_cast<int>(size_.y) };
  texture_.drawClip(dest, clip_);
}

void Sprite::
draw(Vec2 pos) {
  draw(pos.x, pos.y);
}

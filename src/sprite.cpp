/**
  sprite.cpp
 */
#include "sprite.h"

Sprite::
Sprite(const std::string& path) : texture_(path) {
  clip_ = { 0, 0, texture_.getWidth(), texture_.getHeight() };
}

Sprite::
Sprite(const std::string& path, Vec2f pos) : Sprite(path) {
  pos_ = pos;
}

Sprite::
Sprite(const std::string& path, Vec2f pos, Rect clip) : Sprite(path, pos) {
  clip_ = clip;
}

Sprite::
Sprite(Texture texture) : texture_(texture) {
  clip_ = { 0, 0, texture_.getWidth(), texture_.getHeight() };
}

Sprite::
Sprite(Texture texture, Vec2f pos) : Sprite(texture) {
  pos_ = pos;
}

Sprite::
Sprite(Texture texture, Vec2f pos, Rect clip) : Sprite(texture, pos) {
  clip_ = clip;
}

void Sprite::
draw() {
  texture_.drawFrame(pos_, clip_);
}

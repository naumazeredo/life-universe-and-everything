/**
  sprite.cpp
 */
#include "sprite.h"

Sprite::
Sprite(const std::string& path) {
  setTexture(path);
}

Sprite::
Sprite(const std::string& path, Rectf dest) : Sprite(path) {
  dest_ = dest;
}

Sprite::
Sprite(const std::string& path, Rectf dest, Rect clip) : Sprite(path, dest) {
  clip_ = clip;
}

Sprite::
Sprite(Texture texture) {
  setTexture(texture);
}

Sprite::
Sprite(Texture texture, Rectf dest) : Sprite(texture) {
  dest_ = dest;
}

Sprite::
Sprite(Texture texture, Rectf dest, Rect clip) : Sprite(texture, dest) {
  clip_ = clip;
}

void Sprite::
setTexture(Texture texture) {
  texture_ = texture;
  clip_ = { 0, 0, texture_.getWidth(), texture_.getHeight() };
}

void Sprite::
draw() {
  texture_.drawClip(dest_, clip_);
}

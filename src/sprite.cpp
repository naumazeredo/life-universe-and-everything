/**
  sprite.cpp
 */
#include "sprite.h"
#include "game.h"

Sprite::
Sprite(const std::string& path) {
  setTexture(Texture(path));
}

Sprite::
Sprite(const std::string& path, Rect clip) {
  setTexture(Texture(path));
  setClip(clip);
}

Sprite::
Sprite(const std::string& path, Vec2f pivot) : Sprite(path) {
  setPivot(pivot);
}

Sprite::
Sprite(const std::string& path, Rect clip, Vec2f pivot) : Sprite(path, clip) {
  setPivot(pivot);
}

void Sprite::
setTexture(Texture texture) {
  texture_ = texture;
  clip_ = { 0, 0, texture_.getWidth(), texture_.getHeight() };
}

void Sprite::
setTexture(Texture texture, Rect clip) {
  texture_ = texture;
  clip_ = clip;
}

void Sprite::
draw(Vec2 pos) const {
  const Rect dest {
    static_cast<int>(pos.x - pivot_.x * clip_.w),
    static_cast<int>(pos.y - pivot_.y * clip_.h),
    clip_.w, clip_.h
  };

  texture_.drawClip(dest, clip_);
}

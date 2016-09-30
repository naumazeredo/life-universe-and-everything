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
  Sprite(const std::string&, Vec2f, Rect);
  Sprite(Texture);
  Sprite(Texture, Vec2f);
  Sprite(Texture, Vec2f, Rect);

  inline Texture getTexture() const { return texture_; }
  inline Vec2f getPos() const       { return pos_;     }
  inline Rect getClip() const       { return clip_;    }

  inline void setTexture(Texture texture)   { texture_ = texture; }
  inline void setX(float x)                 { pos_.x = x;         }
  inline void setY(float y)                 { pos_.y = y;         }
  inline void setPos(Vec2f pos)             { pos_ = pos;         }
  inline void setClip(Rect clip)            { clip_ = clip;       }

  void draw();

private:
  Texture texture_;

  Vec2f pos_ = { 0.0f, 0.0f };
  Rect clip_ = { 0, 0, 0, 0 };
};

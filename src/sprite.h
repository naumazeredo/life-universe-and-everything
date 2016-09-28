/**
  sprite.h
 */
#pragma once

#include <string>
#include "texture.h"

class Sprite {
public:
  Sprite(const std::string&);
  Sprite(const std::string&, float, float);
  Sprite(Texture);
  Sprite(Texture, float, float);

  inline Texture getTexture() const { return texture_; }
  inline float getX() const           { return x_; }
  inline float getY() const           { return y_; }

  inline void setTexture(Texture texture) { texture_ = texture; }
  inline void setX(float x)               { x_ = x; }
  inline void setY(float y)               { y_ = y; }

  void draw();

private:
  Texture texture_;

  float x_ = 0.0f;
  float y_ = 0.0f;

  //int clipX_, clipY_, clipW_, clipH_;
};

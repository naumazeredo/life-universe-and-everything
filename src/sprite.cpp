/**
  sprite.cpp
 */
#include "sprite.h"

Sprite::
Sprite(const std::string& path) :
    texture_(path)
{}

Sprite::
Sprite(const std::string& path, float x, float y) :
    texture_(path), x_(x), y_(y)
{}

Sprite::
Sprite(Texture texture) :
    texture_(texture)
{}

Sprite::
Sprite(Texture texture, float x, float y) :
    texture_(texture), x_(x), y_(y)
{}

void Sprite::
draw() {
  texture_.draw(static_cast<int>(x_), static_cast<int>(y_));
}

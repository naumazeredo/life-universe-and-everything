/**
  button.cpp
 */
#include "button.h"

#include "mouse.h"

Button::
Button(Vec2f pos, Sprite sprite) :
    pos_(pos), sprite_(sprite)
{}

Button::
Button(Vec2f pos, Sprite sprite, ButtonCallback callback) :
    Button(pos, sprite)
{
  onMouseClick_ = callback;
}

void Button::
draw() {
  sprite_.draw(pos_);
}

void Button::
update() {
  auto size = sprite_.getSize();
  Rectf rect = { pos_.x, pos_.y, size.x, size.y };
  if (pointInsideRect(Mouse::getPosition(), rect) and
      Mouse::isButtonPressed(Mouse::Left)) {
    onMouseClick_(*this);
  }
}

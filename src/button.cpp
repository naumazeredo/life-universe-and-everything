/**
  button.cpp
 */
#include "button.h"

#include "mouse.h"

Button::
Button(Vec2f pos, Sprite sprite) :
    pos_(pos), sprite_(sprite)
{
  sprite_.setPosition(pos_);
}

void Button::
draw() {
  sprite_.draw(pos_);
}

void Button::
update() {
  const auto rect = sprite_.getDrawRect();
  if (pointInsideRect(Mouse::getPosition(), rect)) {
    if (onMouseClick_ and Mouse::isButtonPressed(Mouse::Left))
      onMouseClick_(*this);
    if (onMouseEnter_ and !pointInsideRect(Mouse::getLastPosition(), rect))
      onMouseEnter_(*this);
  } else {
    if (onMouseExit_ and pointInsideRect(Mouse::getLastPosition(), rect))
      onMouseExit_(*this);
  }
}

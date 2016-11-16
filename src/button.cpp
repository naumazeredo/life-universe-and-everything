/**
  button.cpp
 */
#include "button.h"

#include "mouse.h"

// TODO: use Event Queue and Finite State Machine to handle this!
void Button::
updateInternal() {
  const auto rect = getDrawRect();

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

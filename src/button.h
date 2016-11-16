/**
  button.h
 */
#pragma once

#include <functional>
#include "util/types.h"
#include "widget.h"
#include "image.h"

class Button;

typedef std::function<void(Button&)> ButtonCallback;

class Button : public Image {
public:
  Button() {}
  //Button(Vec2f pos, Sprite sprite) : pos_ { pos }, sprite_ { sprite } {}
  virtual ~Button() {}

  inline void setMouseClickCallback(ButtonCallback callback) { onMouseClick_ = callback; }
  inline void setMouseEnterCallback(ButtonCallback callback) { onMouseEnter_ = callback; }
  inline void setMouseExitCallback (ButtonCallback callback) { onMouseExit_  = callback; }

protected:
  virtual void updateInternal() override;

private:
  ButtonCallback onMouseClick_,
                 onMouseEnter_,
                 onMouseExit_;
};

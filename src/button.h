/**
  button.h
 */
#pragma once

#include <functional>
#include "util/types.h"
#include "sprite.h"

class Button;

typedef std::function<void(Button&)> ButtonCallback;

// TODO FIXME URGENT: Redo Button/Sprite API for consistency

class Button {
public:
  Button() = default;
  Button(Vec2f, Sprite);
  Button(Vec2f, Sprite, ButtonCallback);

  inline Vec2f getPos() const          { return pos_; }
  inline Sprite& getSprite() { return sprite_; }
  inline Sprite getSprite() const { return sprite_; }

  inline void setPos(Vec2f pos)        { pos_ = pos; }
  inline void setSprite(Sprite sprite) { sprite_ = sprite; }
  inline void setMouseClickCallback(ButtonCallback callback) { onMouseClick_ = callback; }
  inline void setMouseEnterCallback(ButtonCallback callback) { onMouseEnter_ = callback; }
  inline void setMouseExitCallback (ButtonCallback callback) { onMouseExit_  = callback; }

  void draw();
  void update();
private:
  Vec2f pos_ = { 0, 0 };
  Sprite sprite_;
  ButtonCallback onMouseClick_,
                 onMouseEnter_,
                 onMouseExit_;
};

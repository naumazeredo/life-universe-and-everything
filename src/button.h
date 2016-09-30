/**
  button.h
 */
#pragma once

#include <functional>
#include "util/types.h"
#include "sprite.h"

class Button;

typedef std::function<void(Button&)> ButtonCallback;

class Button {
public:
  Button(Vec2f, Sprite);
  Button(Vec2f, Sprite, ButtonCallback);

  inline Vec2f getPos() const { return pos_; }

  inline void setPos(Vec2f pos)          { pos_ = pos; }
  inline void setSprite(Sprite sprite) { sprite_ = sprite; }
  inline void setMouseClickCallback(ButtonCallback callback) {
    onMouseClick_ = callback;
  }

  void draw();
  void update(int, int, bool);
private:
  Vec2f pos_;
  Sprite sprite_;
  ButtonCallback onMouseClick_;
};

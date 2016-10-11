/**
  mouse.h
 */
#pragma once

#include <SDL2/SDL_mouse.h>
#include "util/types.h"

class Mouse {
public:
  enum Button { LEFT = 0x01, MIDDLE = 0x02, RIGHT = 0x04, X1 = 0x08, X2 = 0x10 };

  static inline Vec2 getPosition()         { return pos_; }
  static inline Vec2 getRelativePosition() { return relativePos_; }

  static inline bool getButtonDown(Button button)     { return state_ & button; }
  static inline bool getButtonUp(Button button)       { return (!state_) & button; }
  static inline bool getButtonPressed(Button button)  { return relativeState_ & state_ & button; }
  static inline bool getButtonReleased(Button button) { return relativeState_ & (!state_) & button; }

  static void update() {
    Vec2 pos;
    u32 state      = SDL_GetMouseState(&pos.x, &pos.y);

    relativePos_ = { pos.x - pos_.x, pos.y - pos_.y };
    pos_ = pos;

    relativeState_ = state_ ^ state;
    state_         = state;
  }

private:
  static Vec2 pos_, relativePos_;
  static u32 state_, relativeState_;
};

/**
  mouse.cpp
  */
#include "mouse.h"

namespace Mouse {

// Internals
namespace {
Vec2 pos_           { 0, 0 },
     relativePos_   { 0, 0 };
u32  state_         { 0 },
     relativeState_ { 0 };
}

Vec2 getPosition()         { return pos_; }
Vec2 getRelativePosition() { return relativePos_; }

bool getButtonDown(Button button)     { return state_ & button; }
bool getButtonUp(Button button)       { return (!state_) & button; }
bool getButtonPressed(Button button)  { return relativeState_ & state_ & button; }
bool getButtonReleased(Button button) { return relativeState_ & (!state_) & button; }

void update() {
  Vec2 pos;
  u32 state      = SDL_GetMouseState(&pos.x, &pos.y);

  relativePos_ = { pos.x - pos_.x, pos.y - pos_.y };
  pos_ = pos;

  relativeState_ = state_ ^ state;
  state_         = state;
}

}

/**
  mouse.cpp
  */
#include "mouse.h"

namespace Mouse {

// Internals
namespace {
Vec2 pos           { 0, 0 },
     relativePos   { 0, 0 };
u32  state         { 0 },
     relativeState { 0 };
}

Vec2 getPosition()         { return pos; }
Vec2 getRelativePosition() { return relativePos; }

bool isButtonDown(Button button)     { return state & button; }
bool isButtonUp(Button button)       { return (!state) & button; }
bool isButtonPressed(Button button)  { return relativeState & state & button; }
bool isButtonReleased(Button button) { return relativeState & (!state) & button; }

void update() {
  Vec2 newPos;
  u32 newState = SDL_GetMouseState(&newPos.x, &newPos.y);

  relativePos = { newPos.x - pos.x, newPos.y - pos.y };
  pos = newPos;

  relativeState = newState ^ state;
  state         = newState;
}

}

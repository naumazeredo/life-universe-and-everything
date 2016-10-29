/**
  mouse.h
  */
#pragma once

#include <SDL2/SDL_mouse.h>
#include "util/types.h"

namespace Mouse {

enum Button {
  Left   = 0x01,
  Middle = 0x02,
  Right  = 0x04,
  X1     = 0x08,
  X2     = 0x10
};

Vec2 getPosition();
Vec2 getRelativePosition();
Vec2 getLastPosition();

bool isButtonDown(Button);
bool isButtonUp(Button);
bool isButtonPressed(Button);
bool isButtonReleased(Button);

void update();

}

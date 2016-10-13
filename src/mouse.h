/**
  mouse.h
  */
#pragma once

#include <SDL2/SDL_mouse.h>
#include "util/types.h"

namespace Mouse {

enum Button { LEFT = 0x01, MIDDLE = 0x02, RIGHT = 0x04, X1 = 0x08, X2 = 0x10 };

Vec2 getPosition();
Vec2 getRelativePosition();

bool isButtonDown(Button);
bool isButtonUp(Button);
bool isButtonPressed(Button);
bool isButtonReleased(Button);

void update();

}

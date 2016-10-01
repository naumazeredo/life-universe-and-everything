/**
  mouse.cpp
 */
#include "mouse.h"

Vec2 Mouse::pos_ = { 0, 0 };
Vec2 Mouse::relativePos_ = { 0, 0 };

u32 Mouse::state_ = 0;
u32 Mouse::relativeState_ = 0;

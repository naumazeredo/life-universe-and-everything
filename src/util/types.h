/**
  types.h
 */
#pragma once

#include <cstdint>
#include <SDL2/SDL_rect.h>

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef SDL_Point Vec2;
typedef SDL_Rect  Rect;

struct Vec2f {
  float x, y;
  operator Vec2() {
    return { static_cast<int>(x), static_cast<int>(y) };
  }
};

struct Rectf {
  float x, y, w, h;
  operator Rect() {
    return {
      static_cast<int>(x), static_cast<int>(y),
      static_cast<int>(w), static_cast<int>(h)
    };
  }
};

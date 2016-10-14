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
typedef SDL_Rect Rect;

struct Vec2f;
struct Rectf;
struct Color;

struct Vec2f {
  float x, y;
  operator Vec2()     { return { (int)x, (int)y }; }
};

struct Rectf {
  float x, y, w, h;
  Vec2f pos() const   { return { x, y }; }
  Vec2f size() const  { return { w, h }; }
  operator Rect()     { return { (int)x, (int)y, (int)w, (int)h }; }
};

struct Color {
  u8 r, g, b, a;
  operator SDL_Color() { return { r, g, b, a }; }
};

// Functions

inline bool pointInsideRect(Vec2 p, Rect r) {
  return (p.x >= r.x and p.x < r.x+r.w and p.y >= r.y and p.y < r.y+r.h);
}

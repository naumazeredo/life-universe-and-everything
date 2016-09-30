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

struct Vec2;
struct Vec2f;
struct Rect;
struct Rectf;

struct Vec2 {
  int x, y;
  operator SDL_Point() { return { x, y }; }
};

struct Rect {
  int x, y, w, h;
  Vec2 pos() const     { return { x, y }; }
  Vec2 size() const    { return { w, h }; }
  operator SDL_Rect()  { return { x, y, w, h }; }
};

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


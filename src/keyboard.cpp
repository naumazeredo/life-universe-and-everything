/**
  keyboard.cpp
  */
#include "keyboard.h"

#include <bitset>
#include <array>
#include <cassert>
#include <SDL2/SDL_keyboard.h>
#include "util/types.h"

namespace Keyboard {

namespace {

const std::array<SDL_Keycode, Key::KeyCount> mapping {
  SDLK_a,
  SDLK_b,
  SDLK_c,
  SDLK_d,
  SDLK_e,
  SDLK_f,
  SDLK_g,
  SDLK_h,
  SDLK_i,
  SDLK_j,
  SDLK_k,
  SDLK_l,
  SDLK_m,
  SDLK_n,
  SDLK_o,
  SDLK_p,
  SDLK_q,
  SDLK_r,
  SDLK_s,
  SDLK_t,
  SDLK_u,
  SDLK_v,
  SDLK_w,
  SDLK_x,
  SDLK_y,
  SDLK_z,
  SDLK_0,
  SDLK_1,
  SDLK_2,
  SDLK_3,
  SDLK_4,
  SDLK_5,
  SDLK_6,
  SDLK_7,
  SDLK_8,
  SDLK_9,
  SDLK_ESCAPE,
  SDLK_LCTRL,
  SDLK_LSHIFT,
  SDLK_LALT,
  SDLK_LGUI,
  SDLK_RCTRL,
  SDLK_RSHIFT,
  SDLK_RALT,
  SDLK_RGUI,
  SDLK_MENU,
  SDLK_LEFTBRACKET,
  SDLK_RIGHTBRACKET,
  SDLK_SEMICOLON,
  SDLK_COMMA,
  SDLK_PERIOD,
  SDLK_QUOTE,
  SDLK_SLASH,
  SDLK_BACKSLASH,
  SDLK_EQUALS,
  SDLK_SPACE,
  SDLK_RETURN,
  SDLK_BACKSPACE,
  SDLK_TAB,
  SDLK_PAGEUP,
  SDLK_PAGEDOWN,
  SDLK_END,
  SDLK_HOME,
  SDLK_INSERT,
  SDLK_DELETE,
  SDLK_KP_PLUS,
  SDLK_KP_MINUS,
  SDLK_KP_MULTIPLY,
  SDLK_KP_DIVIDE,
  SDLK_LEFT,
  SDLK_RIGHT,
  SDLK_UP,
  SDLK_DOWN,
  SDLK_KP_0,
  SDLK_KP_1,
  SDLK_KP_2,
  SDLK_KP_3,
  SDLK_KP_4,
  SDLK_KP_5,
  SDLK_KP_6,
  SDLK_KP_7,
  SDLK_KP_8,
  SDLK_KP_9,
  SDLK_F1,
  SDLK_F2,
  SDLK_F3,
  SDLK_F4,
  SDLK_F5,
  SDLK_F6,
  SDLK_F7,
  SDLK_F8,
  SDLK_F9,
  SDLK_F10,
  SDLK_F11,
  SDLK_F12,
  SDLK_PAUSE
};

std::bitset<Key::KeyCount> keyState, relativeKeyState;

SDL_Keycode getKeycode(Key key) {
  switch(key) {
    case A:         return SDLK_a;
    case B:         return SDLK_b;
    case C:         return SDLK_c;
    case D:         return SDLK_d;
    case E:         return SDLK_e;
    case F:         return SDLK_f;
    case G:         return SDLK_g;
    case H:         return SDLK_h;
    case I:         return SDLK_i;
    case J:         return SDLK_j;
    case K:         return SDLK_k;
    case L:         return SDLK_l;
    case M:         return SDLK_m;
    case N:         return SDLK_n;
    case O:         return SDLK_o;
    case P:         return SDLK_p;
    case Q:         return SDLK_q;
    case R:         return SDLK_r;
    case S:         return SDLK_s;
    case T:         return SDLK_t;
    case U:         return SDLK_u;
    case V:         return SDLK_v;
    case W:         return SDLK_w;
    case X:         return SDLK_x;
    case Y:         return SDLK_y;
    case Z:         return SDLK_z;
    case Num0:      return SDLK_0;
    case Num1:      return SDLK_1;
    case Num2:      return SDLK_2;
    case Num3:      return SDLK_3;
    case Num4:      return SDLK_4;
    case Num5:      return SDLK_5;
    case Num6:      return SDLK_6;
    case Num7:      return SDLK_7;
    case Num8:      return SDLK_8;
    case Num9:      return SDLK_9;
    case Escape:    return SDLK_ESCAPE;
    case Menu:      return SDLK_MENU;
    case LBracket:  return SDLK_LEFTBRACKET;
    case RBracket:  return SDLK_RIGHTBRACKET;
    case SemiColon: return SDLK_SEMICOLON;
    case Comma:     return SDLK_COMMA;
    case Period:    return SDLK_PERIOD;
    case Quote:     return SDLK_QUOTE;
    case Slash:     return SDLK_SLASH;
    case BackSlash: return SDLK_BACKSLASH;
    case Equal:     return SDLK_EQUALS;
    case Space:     return SDLK_SPACE;
    case Return:    return SDLK_RETURN;
    case BackSpace: return SDLK_BACKSPACE;
    case Tab:       return SDLK_TAB;
    case PageUp:    return SDLK_PAGEUP;
    case PageDown:  return SDLK_PAGEDOWN;
    case End:       return SDLK_END;
    case Home:      return SDLK_HOME;
    case Insert:    return SDLK_INSERT;
    case Delete:    return SDLK_DELETE;
    case Add:       return SDLK_KP_PLUS;
    case Subtract:  return SDLK_KP_MINUS;
    case Multiply:  return SDLK_KP_MULTIPLY;
    case Divide:    return SDLK_KP_DIVIDE;
    case Left:      return SDLK_LEFT;
    case Right:     return SDLK_RIGHT;
    case Up:        return SDLK_UP;
    case Down:      return SDLK_DOWN;
    case Numpad0:   return SDLK_KP_0;
    case Numpad1:   return SDLK_KP_1;
    case Numpad2:   return SDLK_KP_2;
    case Numpad3:   return SDLK_KP_3;
    case Numpad4:   return SDLK_KP_4;
    case Numpad5:   return SDLK_KP_5;
    case Numpad6:   return SDLK_KP_6;
    case Numpad7:   return SDLK_KP_7;
    case Numpad8:   return SDLK_KP_8;
    case Numpad9:   return SDLK_KP_9;
    case F1:        return SDLK_F1;
    case F2:        return SDLK_F2;
    case F3:        return SDLK_F3;
    case F4:        return SDLK_F4;
    case F5:        return SDLK_F5;
    case F6:        return SDLK_F6;
    case F7:        return SDLK_F7;
    case F8:        return SDLK_F8;
    case F9:        return SDLK_F9;
    case F10:       return SDLK_F10;
    case F11:       return SDLK_F11;
    case F12:       return SDLK_F12;
    case Pause:     return SDLK_PAUSE;
    default: break;
  }
  return 0;
}

}

void update() {
  const u8* keys = SDL_GetKeyboardState(nullptr);

  keyState = [&] {
    std::bitset<Key::KeyCount> newKeyState;
    for (int i = Key::A; i < Key::KeyCount; ++i) {
      Key key = static_cast<Key>(i);
      if (keys[SDL_GetScancodeFromKey(getKeycode(key))])
        newKeyState.set(key);
    }
    relativeKeyState = keyState ^ newKeyState;

    return newKeyState;
  }();
}

bool isKeyDown(Key key) {
  assert(key >= Key::A and key < Key::KeyCount);
  return keyState[key];
}

bool isKeyUp(Key key) {
  assert(key >= Key::A and key < Key::KeyCount);
  return !keyState[key];
}

bool isKeyPressed(Key key) {
  assert(key >= Key::A and key < Key::KeyCount);
  return relativeKeyState[key] and keyState[key];
}

bool isKeyReleased(Key key) {
  assert(key >= Key::A and key < Key::KeyCount);
  return relativeKeyState[key] and !keyState[key];
}

}

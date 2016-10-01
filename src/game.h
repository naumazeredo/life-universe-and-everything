/**
  game.h
 */

#pragma once

#include <string>
#include "util/types.h"

struct SDL_Window;
struct SDL_Renderer;
class TextureManager;
class FontManager;

class Game {
public:
  ~Game();

  // Singleton non-copy
  Game(const Game&) = delete;
  Game& operator=(const Game&) = delete;

  // Singleton instance
  inline static Game& getInstance() {
    static Game instance;
    return instance;
  }

  void start(const std::string&, int, int);

  //inline SDL_Window*   getWindow() const { return window_; }
  inline SDL_Renderer* getRenderer() const { return renderer_; }
  Vec2 getWindowSize() const;

  void setDrawColor(Color);
  void drawLine(Vec2, Vec2);
  void drawRect(Rect);

protected:
  // Singleton private constructor
  Game();

  void loop();
  void loadContent();
  void logic();

  SDL_Window*     window_;
  SDL_Renderer*   renderer_;
  TextureManager& textureManager_;
  FontManager&    fontManager_;
};

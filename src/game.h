/**
  game.h
 */

#pragma once

#include <string>

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

  //inline SDL_Window*   getWindow()   { return window_; }
  inline SDL_Renderer* getRenderer() { return renderer_; }

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

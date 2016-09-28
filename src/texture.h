/**
  texture.h
 */

#pragma once

#include <string>

struct SDL_Texture;
class TextureManager;

class Texture {
public:
  Texture();
  Texture(const std::string&);

  void load(const std::string&);
  void destroy();

  void draw(int, int);
  //void drawFrame();

private:
  SDL_Texture* texture_;
  int width_, height_;
};

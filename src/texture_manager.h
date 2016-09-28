/**
  texture_manager.h
 */

#pragma once

#include <map>
#include <string>
#include <vector>

#include "texture.h"

struct SDL_Texture;

class TextureManager {
public:
  ~TextureManager();

  // Singleton non-copy
  TextureManager(const TextureManager&) = delete;
  TextureManager& operator=(const TextureManager&) = delete;

  // Singleton instance
  inline static TextureManager& getInstance() {
    static TextureManager instance;
    return instance;
  }

  Texture& loadTexture(const std::string&);
  void destroyAllTextures();

private:
  // Singleton private constructor
  TextureManager() = default;

  std::map<std::string, Texture> textures_;
};

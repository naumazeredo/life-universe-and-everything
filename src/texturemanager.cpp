/**
  texturemanager.cpp
 */
#include "texturemanager.h"

#include <SDL2/SDL_image.h>

TextureManager::
TextureManager() {
  // TODO: error checking
  IMG_Init(IMG_INIT_PNG);
}

TextureManager::
~TextureManager() {
  destroyAllTextures();
  IMG_Quit();
}

Texture TextureManager::
loadTexture(const std::string& path) {
  auto it = textures_.find(path);
  if (it != textures_.end()) {
    return it->second;
  }

  textures_.emplace(path, path);
  return textures_[path];
}

void TextureManager::
destroyAllTextures() {
  for (auto& it : textures_)
    it.second.destroy();
  textures_.clear();
}

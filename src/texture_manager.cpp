/**
  texture_manager.cpp
 */
#include "texture_manager.h"

TextureManager::
~TextureManager() {
  destroyAllTextures();
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

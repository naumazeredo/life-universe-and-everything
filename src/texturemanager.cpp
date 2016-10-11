/**
  texturemanager.cpp
 */
#include "texturemanager.h"

#include <SDL2/SDL_image.h>

namespace TextureManager {

// Internals
namespace {
std::map<std::string, Texture> textures_;
}

void
start() {
  // TODO: error checking
  IMG_Init(IMG_INIT_PNG);
}

void
destroy() {
  destroyAllTextures();
  IMG_Quit();
}

Texture
loadTexture(const std::string& path) {
  auto it = textures_.find(path);
  if (it != textures_.end()) {
    return it->second;
  }

  textures_.emplace(path, path);
  return textures_[path];
}

void
destroyAllTextures() {
  for (auto& it : textures_)
    it.second.destroy();
  textures_.clear();
}

}

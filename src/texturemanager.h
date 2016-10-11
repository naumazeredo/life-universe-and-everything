/**
  texture_manager.h
 */

#pragma once

#include <map>
#include <string>
#include <vector>

#include "texture.h"

struct SDL_Texture;

namespace TextureManager {
void start();
void destroy();

Texture loadTexture(const std::string&);
void destroyAllTextures();
};

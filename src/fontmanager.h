/**
  fontmanager.h
 */
#pragma once

#include <map>
#include "font.h"

class FontManager {
public:
  ~FontManager();

  // Singleton non-copy
  FontManager(const FontManager&) = delete;
  FontManager& operator=(const FontManager&) = delete;

  // Singleton instance
  inline static FontManager& getInstance() {
    static FontManager instance;
    return instance;
  }

  // TODO: Allow another font paths
  Font loadFont(/*const std::string&,*/ int);
  void destroyAllFonts();

private:
  // Singleton private constructor
  FontManager();

  std::map<int, Font> fonts_;
};

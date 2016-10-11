/**
  fontmanager.h
 */
#pragma once

#include <map>
#include "font.h"

namespace FontManager {

void start();
void destroy();

// TODO: Allow another font paths
Font loadFont(/*const std::string&,*/ int);
void destroyAllFonts();

};

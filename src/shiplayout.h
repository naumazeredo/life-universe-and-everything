/**
  shiplayout.h
  */
#pragma once

#include <array>
#include "util/types.h"

namespace ShipLayout {

const i32 TileSize = 18;
const i32 ShipSize = 32;

typedef std::array<std::array<u32, ShipSize>, ShipSize> ShipGrid;

namespace Colors {

const Color Tile   = { 224, 224, 224, 255 };
const Color Wall   = { 32, 32, 32, 255 };
const Color Border = { 192, 192, 192, 255 };

}

}

/**
  shipbuilding.h
 */
#pragma once

#include <unordered_map>
#include <vector>
#include <utility>
#include "util/types.h"

#define SHIP_GRID_SIZE 32

class ShipBuilding {
public:
  enum class SystemType {
    NONE, PILOTING, ENGINE, SHIELDS, WEAPONS
  };

  void draw();
  void update();

private:
  struct Room {
    SystemType system;
    std::vector<std::pair<int, int>> tiles;
  };

  bool createRoom();
  bool assignSystemToRoom(u32, SystemType);

  inline u32 getTileRoom(int x, int y) { return tiles_[x][y]; }
  void removeTileFromRoom(int, int, u32);

  inline void selectTile(int x, int y) { selectedTiles_[x][y] = !selectedTiles_[x][y]; }


  u32 tiles_[SHIP_GRID_SIZE][SHIP_GRID_SIZE] = {};
  u32 roomCount_;
  std::unordered_map<u32, Room> rooms_;

  bool selectedTiles_[SHIP_GRID_SIZE][SHIP_GRID_SIZE] = {};
};

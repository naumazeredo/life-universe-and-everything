/**
  shipbuilding.h
 */
#pragma once

#include <unordered_map>
#include <vector>
//#include <utility>
#include <array>
#include "util/types.h"

// TODO: don't use define for constant!
#define SHIP_GRID_SIZE 32
//typedef std::array<std::array<u32, 32>, 32> ShipGrid;

class ShipBuilding {
public:
  ShipBuilding() : tiles_{}, selectedTiles_{} {}
  void draw();
  void update();

private:
  struct Room {
    u32 system;
    std::vector<std::pair<int, int>> tiles;
  };

  bool createRoom();
  bool assignSystemToRoom(u32, u32);

  inline u32 getTileRoom(int x, int y) { return tiles_[y][x]; }
  void removeTileFromRoom(int, int, u32);

  void setTileSelection(int, int, bool);

  inline bool isTileSelected(int x, int y) const { return selectedTiles_[y][x]; }

  int countConnectedComponents();

  // TODO: use std array
  u32 tiles_[SHIP_GRID_SIZE][SHIP_GRID_SIZE] = {};
  bool selectedTiles_[SHIP_GRID_SIZE][SHIP_GRID_SIZE] = {};
  bool selectingTiles_;

  // TODO: do this better!
  u32 roomCount_;
  std::unordered_map<u32, Room> rooms_;
};

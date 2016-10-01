/**
  ship.h
 */
#pragma once

#include <unordered_map>
#include <vector>
#include <utility>
#include "util/types.h"

class Ship {
public:
  enum class SystemType {
    NONE, PILOTING, ENGINE, SHIELDS, WEAPONS
  };

  Ship() = default;

  bool createRoom(const std::vector<std::pair<int, int>>&);
  bool assignSystemToRoom(u32, SystemType);

  u32 getTileRoom(int, int);

private:
  void removeTileFromRoom(int, int, u32);

  struct Room {
    SystemType system;
    std::vector<std::pair<int, int>> tiles;
  };

  u32 tiles_[64][64] = {};

  u32 roomCount_;
  std::unordered_map<u32, Room> rooms_;
};

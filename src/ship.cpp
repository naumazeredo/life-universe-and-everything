/**
  ship.cpp
 */
#include "ship.h"

#include <algorithm>

bool Ship::
createRoom(const std::vector<std::pair<int, int>>& tiles) {
  // TODO: Verify if is a connected component

  // Add to new room
  roomCount_++;
  Room newRoom { SystemType::NONE, {} };

  for (const auto& pos : tiles) {
    auto x = pos.first;
    auto y = pos.second;
    auto& tile = tiles_[x][y];

    if (tile != 0)
      removeTileFromRoom(x, y, tile);

    newRoom.tiles.push_back(pos);
    tile = roomCount_;
  }

  rooms_[roomCount_] = std::move(newRoom);

  return true;
}

u32 Ship::
getTileRoom(int x, int y) {
  return tiles_[x][y];
}

bool Ship::
assignSystemToRoom(u32 room, SystemType system) {
  if (room == 0 or room >= roomCount_)
    return false;

  rooms_[room].system = system;
  return true;
}

void Ship::
removeTileFromRoom(int x, int y, u32 room) {
  if (room == 0 or room >= roomCount_ or rooms_.find(room) == rooms_.end())
    return;

  auto& tiles = rooms_[room].tiles;
  std::remove(tiles.begin(), tiles.end(), std::make_pair(x, y));

  // If room is empty, erase room
  if (tiles.empty())
    rooms_.erase(room);
}

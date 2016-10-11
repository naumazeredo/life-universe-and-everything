/**
  shipbuilding.cpp
 */
#include "shipbuilding.h"

#include <algorithm>
#include "game.h"
#include "mouse.h"

bool ShipBuilding::
createRoom() {
  // Get tiles vector from selected grid
  std::vector<std::pair<int, int>> tiles;

  for (int y = 0; y < SHIP_GRID_SIZE; ++y)
    for (int x = 0; x < SHIP_GRID_SIZE; ++x)
      if (selectedTiles_[y][x])
        tiles.push_back({ y, x });

  if (tiles.empty())
    return false;

  // TODO: Verify if is a connected component

  // Add to new room
  roomCount_++;
  Room newRoom {};

  for (const auto& pos : tiles) {
    auto x = pos.second;
    auto y = pos.first;
    auto& tile = tiles_[y][x];

    if (tile != 0)
      removeTileFromRoom(x, y, tile);

    newRoom.tiles.push_back(pos);
    tile = roomCount_;
  }

  rooms_[roomCount_] = std::move(newRoom);

  // Reset grid
  for (auto& tilerow : selectedTiles_)
    for (auto& tile : tilerow)
      tile = 0;

  return true;
}

bool ShipBuilding::
assignSystemToRoom(u32 room, u32 system) {
  if (room == 0 or room >= roomCount_)
    return false;

  rooms_[room].system = system;
  return true;
}

void ShipBuilding::
removeTileFromRoom(int x, int y, u32 room) {
  if (room == 0 or room >= roomCount_ or rooms_.find(room) == rooms_.end())
    return;

  auto& tiles = rooms_[room].tiles;
  std::remove(tiles.begin(), tiles.end(), std::make_pair(y, x));

  // If room is empty, erase room
  if (tiles.empty())
    rooms_.erase(room);
}

void ShipBuilding::
draw() {
  auto& game = Game::getInstance();
  Vec2 mousePos = Mouse::getPosition();

  const Vec2 WINDOW_SIZE = game.getWindowSize();
  const int TILE_SIZE = 16;

  const Rect GRID_RECT = {
    WINDOW_SIZE.x / 2 - (TILE_SIZE + 1) * SHIP_GRID_SIZE / 2,
    WINDOW_SIZE.y / 2 - (TILE_SIZE + 1) * SHIP_GRID_SIZE / 2,
    (TILE_SIZE + 1) * SHIP_GRID_SIZE,
    (TILE_SIZE + 1) * SHIP_GRID_SIZE
  };

  // Grid
  game.setDrawColor({ 64, 64, 64, 255 });
  game.drawRect(GRID_RECT);

  game.setDrawColor({ 32, 32, 32, 255 });
  for (int i = 0; i <= SHIP_GRID_SIZE; ++i) {
    int v = i * 17;

    game.drawLine({ GRID_RECT.x              , GRID_RECT.y + v           },
                  { GRID_RECT.x + GRID_RECT.w, GRID_RECT.y + v           });
    game.drawLine({ GRID_RECT.x + v          , GRID_RECT.y               },
                  { GRID_RECT.x + v          , GRID_RECT.y + GRID_RECT.h });
  }

  // Active tiles
  game.setDrawColor({ 224, 224, 224, 255 });
  for (int i = 0; i < SHIP_GRID_SIZE; ++i) {
    for (int j = 0; j < SHIP_GRID_SIZE; ++j) {
      if (tiles_[i][j]) {
        int y = i * 17 + GRID_RECT.y + 1,
            x = j * 17 + GRID_RECT.x + 1;
        game.drawRect({ x, y, TILE_SIZE, TILE_SIZE });
      }
    }
  }

  // Selected tiles
  game.setDrawColor({ 128, 150, 128, 255 });
  for (int i = 0; i < SHIP_GRID_SIZE; ++i) {
    for (int j = 0; j < SHIP_GRID_SIZE; ++j) {
      if (selectedTiles_[i][j]) {
        int y = i * 17 + GRID_RECT.y + 1,
            x = j * 17 + GRID_RECT.x + 1;
        game.drawRect({ x, y, TILE_SIZE, TILE_SIZE });
      }
    }
  }

  // Mouse over tile
  if (pointInsideRect(mousePos, GRID_RECT)) {
    Vec2 tileMouse = {
      (mousePos.x - GRID_RECT.x) / (TILE_SIZE + 1),
      (mousePos.y - GRID_RECT.y) / (TILE_SIZE + 1)
    };

    int y = tileMouse.y * 17 + GRID_RECT.y + 1,
        x = tileMouse.x * 17 + GRID_RECT.x + 1;

    game.setDrawColor({ 128, 224, 128, 255 });
    game.drawRect({ x, y, TILE_SIZE, TILE_SIZE });
  }
}

void ShipBuilding::
update() {
  auto& game = Game::getInstance();
  Vec2 mousePos = Mouse::getPosition();

  const Vec2 WINDOW_SIZE = game.getWindowSize();
  const int TILE_SIZE = 16;

  const Rect GRID_RECT = {
    WINDOW_SIZE.x / 2 - (TILE_SIZE + 1) * SHIP_GRID_SIZE / 2,
    WINDOW_SIZE.y / 2 - (TILE_SIZE + 1) * SHIP_GRID_SIZE / 2,
    (TILE_SIZE + 1) * SHIP_GRID_SIZE,
    (TILE_SIZE + 1) * SHIP_GRID_SIZE
  };

  if (pointInsideRect(mousePos, GRID_RECT) and
      Mouse::getButtonPressed(Mouse::Button::LEFT)) {
    Vec2 tileMouse = {
      (mousePos.x - GRID_RECT.x) / (TILE_SIZE + 1),
      (mousePos.y - GRID_RECT.y) / (TILE_SIZE + 1)
    };

    selectTile(tileMouse.x, tileMouse.y);
  }

  if (Mouse::getButtonPressed(Mouse::Button::RIGHT)) {
    createRoom();
  }
}


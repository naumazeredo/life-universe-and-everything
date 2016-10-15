/**
  shipbuilding.cpp
 */
#include "shipbuilding.h"

#include <unordered_map>
#include <vector>
#include <array>
#include <algorithm>
#include <functional>
#include "util/types.h"
#include "game.h"
#include "mouse.h"
#include "keyboard.h"

namespace ShipBuilding {

const i32 TILE_SIZE      = 18;
const i32 SHIP_GRID_SIZE = 32;
typedef std::array<std::array<u32, SHIP_GRID_SIZE>, SHIP_GRID_SIZE> ShipGrid;

// Internals
namespace {

struct Room {
  u32 system;
  std::vector<std::pair<int, int>> tiles;
};

ShipGrid tiles_         = {},
         selectedTiles_ = {};

// TODO: Do this better!
u32 roomCount_;
std::unordered_map<u32, Room> rooms_;

bool createRoom();
bool assignSystemToRoom(u32, u32);
void drawRoom(u32);
void removeTileFromRoom(int, int, u32);
void setTileSelection(int, int, bool);
int countConnectedComponents(const ShipGrid&);

u32 getTileRoom(int x, int y) { return tiles_[y][x]; }
bool isTileSelected(int x, int y) { return selectedTiles_[y][x]; }

bool
createRoom() {
  // Verify if selected tiles are connected
  auto merge = [](const ShipGrid& a, const ShipGrid& b) {
    ShipGrid r = a;
    for (u32 i = 0; i < a.size(); ++i)
      for (u32 j = 0; j < a[i].size(); ++j)
        r[i][j] += b[i][j];
    return r;
  };

  if (countConnectedComponents(selectedTiles_) != 1 or
      countConnectedComponents(merge(tiles_, selectedTiles_)) != 1)
    return false;

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
    const auto y = pos.first;
    const auto x = pos.second;
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

bool
assignSystemToRoom(u32 room, u32 system) {
  if (room == 0 or room >= roomCount_)
    return false;

  rooms_[room].system = system;
  return true;
}

void
drawRoom(u32 room) {
  Game::setDrawColor({ 224, 224, 224, 255 });

  const Vec2 WINDOW_SIZE = Game::getWindowSize();
  const Rect GRID_RECT = {
    WINDOW_SIZE.x / 2 - TILE_SIZE * SHIP_GRID_SIZE / 2,
    WINDOW_SIZE.y / 2 - TILE_SIZE * SHIP_GRID_SIZE / 2,
    TILE_SIZE * SHIP_GRID_SIZE,
    TILE_SIZE * SHIP_GRID_SIZE
  };


  const auto& tiles = rooms_[room].tiles;
  auto findTile = [&](int y, int x) {
    for (const auto tile : tiles)
      if (tile.first == y and tile.second == x)
        return true;
    return false;
  };

  // Tile
  for (auto tile : tiles) {
    int y = tile.first  * TILE_SIZE + GRID_RECT.y,
        x = tile.second * TILE_SIZE + GRID_RECT.x;
    Game::drawRect({ x, y, TILE_SIZE, TILE_SIZE });
  }

  // Borders
  auto drawBorder = [&](bool connected) {
    for (auto tile : tiles) {
      int y = tile.first  * TILE_SIZE + GRID_RECT.y,
          x = tile.second * TILE_SIZE + GRID_RECT.x;

      if (!connected) {
        if (findTile(tile.first-1, tile.second) == connected)
          Game::drawLine({ x, y },
                        { x + TILE_SIZE - 1, y });

        if (findTile(tile.first, tile.second-1) == connected)
          Game::drawLine({ x, y },
                        { x, y + TILE_SIZE - 1 });
      }

      if (findTile(tile.first+1, tile.second) == connected)
        Game::drawLine({ x, y + TILE_SIZE - 1 },
                      { x + TILE_SIZE - 1, y + TILE_SIZE - 1 });

      if (findTile(tile.first, tile.second+1) == connected)
        Game::drawLine({ x + TILE_SIZE - 1, y },
                      { x + TILE_SIZE - 1, y + TILE_SIZE - 1 });
    }
  };

  Game::setDrawColor({ 192, 192, 192, 255 });
  drawBorder(true);

  Game::setDrawColor({ 32, 32, 32, 255 });
  drawBorder(false);
}

void
removeTileFromRoom(int x, int y, u32 room) {
  if (room == 0 or room >= roomCount_ or rooms_.find(room) == rooms_.end())
    return;

  auto& tiles = rooms_[room].tiles;
  const auto last = std::remove(tiles.begin(), tiles.end(), std::make_pair(y, x));
  tiles.resize(std::distance(tiles.begin(), last));

  // If room is empty, erase room
  if (tiles.empty())
    rooms_.erase(room);
}

// TODO: add callback if couldn't select
void
setTileSelection(int x, int y, bool select) {
  selectedTiles_[y][x] = select;
}

int
countConnectedComponents(const ShipGrid& tiles) {
  int connectedComponents = 0;

  // TODO: std::array!
  ShipGrid visited {};

  std::function<void(int, int)> floodfill = [&](int y, int x) {
    if (visited[y][x] or
        y < 0 or y >= SHIP_GRID_SIZE or
        x < 0 or x >= SHIP_GRID_SIZE)
      return;
    visited[y][x] = 1;

    if (tiles[y][x]) {
      floodfill(y-1, x);
      floodfill(y+1, x);
      floodfill(y, x-1);
      floodfill(y, x+1);
    }
  };

  for (int y = 0; y < SHIP_GRID_SIZE; ++y) {
    for (int x = 0; x < SHIP_GRID_SIZE; ++x) {
      const auto tileActive = tiles[y][x];
      if (!visited[y][x] and tileActive) {
        // Flood Fill
        floodfill(y, x);
        connectedComponents++;
      }
    }
  }

  return connectedComponents;
}

}

void
draw() {
  const Vec2 mousePos = Mouse::getPosition();

  const Vec2 WINDOW_SIZE = Game::getWindowSize();
  const Rect GRID_RECT = {
    WINDOW_SIZE.x / 2 - TILE_SIZE * SHIP_GRID_SIZE / 2,
    WINDOW_SIZE.y / 2 - TILE_SIZE * SHIP_GRID_SIZE / 2,
    TILE_SIZE * SHIP_GRID_SIZE,
    TILE_SIZE * SHIP_GRID_SIZE
  };

  // Grid
  Game::setDrawColor({ 64, 64, 64, 255 });
  Game::drawRect(GRID_RECT);

  Game::setDrawColor({ 48, 48, 48, 255 });
  for (int i = 0; i <= SHIP_GRID_SIZE; ++i) {
    int y = i * TILE_SIZE + GRID_RECT.y-1,
        x = i * TILE_SIZE + GRID_RECT.x-1;
    Game::drawLine({ GRID_RECT.x - 1, y }, { GRID_RECT.x + GRID_RECT.w - 1, y });
    Game::drawLine({ x, GRID_RECT.y - 1 }, { x, GRID_RECT.y + GRID_RECT.h - 1 });
  }

  // Rooms
  for (auto room : rooms_)
    drawRoom(room.first);

  // Selected tiles
  Game::setDrawColor({ 128, 170, 128, 192 });
  for (int i = 0; i < SHIP_GRID_SIZE; ++i) {
    for (int j = 0; j < SHIP_GRID_SIZE; ++j) {
      if (selectedTiles_[i][j]) {
        int y = i * TILE_SIZE + GRID_RECT.y,
            x = j * TILE_SIZE + GRID_RECT.x;
        Game::drawRect({ x, y, TILE_SIZE, TILE_SIZE });
      }
    }
  }

  // Mouse over tile
  if (pointInsideRect(mousePos, GRID_RECT)) {
    Vec2 tileMouse = {
      (mousePos.x - GRID_RECT.x) / TILE_SIZE,
      (mousePos.y - GRID_RECT.y) / TILE_SIZE
    };

    int y = tileMouse.y * TILE_SIZE + GRID_RECT.y,
        x = tileMouse.x * TILE_SIZE + GRID_RECT.x;

    Game::setDrawColor({ 128, 224, 128, 192 });
    Game::drawRect({ x, y, TILE_SIZE, TILE_SIZE });
  }
}

void
update() {
  const Vec2 mousePos = Mouse::getPosition();

  const Vec2 WINDOW_SIZE = Game::getWindowSize();
  const Rect GRID_RECT = {
    WINDOW_SIZE.x / 2 - TILE_SIZE * SHIP_GRID_SIZE / 2,
    WINDOW_SIZE.y / 2 - TILE_SIZE * SHIP_GRID_SIZE / 2,
    TILE_SIZE * SHIP_GRID_SIZE,
    TILE_SIZE * SHIP_GRID_SIZE
  };

  if (pointInsideRect(mousePos, GRID_RECT)) {
    const Vec2 tileMouse = {
      (mousePos.x - GRID_RECT.x) / TILE_SIZE,
      (mousePos.y - GRID_RECT.y) / TILE_SIZE
    };

    if (Mouse::isButtonDown(Mouse::Left)) {
      setTileSelection(tileMouse.x, tileMouse.y, true);
    }

    if (Mouse::isButtonDown(Mouse::Right)) {
      setTileSelection(tileMouse.x, tileMouse.y, false);
    }
  }

  if (Keyboard::isKeyDown(Keyboard::Space)) {
    createRoom();
  }
}

}

/**
  hangar.cpp
 */
#include "hangarscene.h"

#include <array>
#include <algorithm>
#include <functional>

#include "game.h"
#include "mouse.h"
#include "keyboard.h"

#include "guimanager.h"

HangarScene::
HangarScene() {
  gui.setFullscreen(true);

  // Parenting
  gui.addChildren({
    &imgTitle,
    &btnBack,
    &btnStart,
    &imgMenuBg
  });

  imgMenuBg.addChildren({
    &btnMenuTile,
    &btnMenuDoor,
    &btnMenuExtra
  });
}

bool HangarScene::
createRoom() {
  // Verify if selected tiles are connected
  // TODO: use C++14 to auto in lambda parameters
  auto merge = [](const ShipLayout::ShipGrid& a, const ShipLayout::ShipGrid& b) {
    auto r = a;
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

  for (int y = 0; y < ShipLayout::ShipSize; ++y)
    for (int x = 0; x < ShipLayout::ShipSize; ++x)
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

bool HangarScene::
assignSystemToRoom(u32 room, u32 system) {
  if (room == 0 or room >= roomCount_)
    return false;

  rooms_[room].system = system;
  return true;
}

void HangarScene::
drawRoom(u32 room) {
  Game::setDrawColor({ 224, 224, 224, 255 });

  const Vec2 WINDOW_SIZE = Game::getWindowSize();
  const auto GRID_SIZE = ShipLayout::TileSize * ShipLayout::ShipSize;
  const Rect GRID_RECT = {
    WINDOW_SIZE.x / 2 - GRID_SIZE / 2, 135,
    GRID_SIZE, GRID_SIZE
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
    int y = tile.first  * ShipLayout::TileSize + GRID_RECT.y,
        x = tile.second * ShipLayout::TileSize + GRID_RECT.x;
    Game::drawRect({ x, y, ShipLayout::TileSize, ShipLayout::TileSize });
  }

  // Borders
  auto drawBorder = [&](bool connected) {
    for (auto tile : tiles) {
      int y = tile.first  * ShipLayout::TileSize + GRID_RECT.y,
          x = tile.second * ShipLayout::TileSize + GRID_RECT.x;

      if (!connected) {
        if (findTile(tile.first-1, tile.second) == connected)
          Game::drawLine({ x, y },
                        { x + ShipLayout::TileSize - 1, y });

        if (findTile(tile.first, tile.second-1) == connected)
          Game::drawLine({ x, y },
                        { x, y + ShipLayout::TileSize - 1 });
      }

      if (findTile(tile.first+1, tile.second) == connected)
        Game::drawLine({ x, y + ShipLayout::TileSize - 1 },
                      { x + ShipLayout::TileSize - 1, y + ShipLayout::TileSize - 1 });

      if (findTile(tile.first, tile.second+1) == connected)
        Game::drawLine({ x + ShipLayout::TileSize - 1, y },
                      { x + ShipLayout::TileSize - 1, y + ShipLayout::TileSize - 1 });
    }
  };

  Game::setDrawColor({ 192, 192, 192, 255 });
  drawBorder(true);

  Game::setDrawColor({ 32, 32, 32, 255 });
  drawBorder(false);
}

void HangarScene::
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
void HangarScene::
setTileSelection(int x, int y, bool select) {
  selectedTiles_[y][x] = select;
}

int HangarScene::
countConnectedComponents(const ShipLayout::ShipGrid& tiles) {
  int connectedComponents = 0;

  // TODO: std::array!
  ShipLayout::ShipGrid visited {};

  std::function<void(int, int)> floodfill = [&](int y, int x) {
    if (visited[y][x] or
        y < 0 or y >= ShipLayout::ShipSize or
        x < 0 or x >= ShipLayout::ShipSize)
      return;
    visited[y][x] = 1;

    if (tiles[y][x]) {
      floodfill(y-1, x);
      floodfill(y+1, x);
      floodfill(y, x-1);
      floodfill(y, x+1);
    }
  };

  for (int y = 0; y < ShipLayout::ShipSize; ++y) {
    for (int x = 0; x < ShipLayout::ShipSize; ++x) {
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

void HangarScene::
load() {
  // Sprites
  imgTitle .setSprite(Sprite { "./assets/images/hangar/hangar-title.png"   });
  imgMenuBg.setSprite(Sprite { "./assets/images/hangar/hangar-menu-bg.png" });
  btnBack  .setSprite(Sprite { "./assets/images/hangar/hangar-back.png"    });
  btnStart .setSprite(Sprite { "./assets/images/hangar/hangar-start.png"   });

  btnMenuTile.setSprite(Sprite {
                          "./assets/images/hangar/hangar-button-tile.png",
                          { 0, 0, 20, 20 }
                        });

  btnMenuDoor.setSprite(Sprite {
                          "./assets/images/hangar/hangar-button-door.png",
                          { 0, 0, 20, 20 },
                        });

  btnMenuExtra.setSprite(Sprite {
                           "./assets/images/hangar/hangar-button-extra.png",
                           { 0, 0, 20, 20 }
                         });

  // Pivoting
  imgTitle    .setPivot({ 0.5f, 0.0f });
  imgMenuBg   .setPivot({ 0.5f, 1.0f });
  btnStart    .setPivot({ 1.0f, 0.0f });
  btnMenuTile .setPivot({ 0.5f, 0.5f });
  btnMenuDoor .setPivot({ 0.5f, 0.5f });
  btnMenuExtra.setPivot({ 0.5f, 0.5f });

  // Position
  imgTitle .setPosition({ 0.5f, 0.0f });
  imgMenuBg.setPosition({ 0.5f, 1.0f });

  btnBack .setPosition({ 0.0f, 0.0f });
  btnStart.setPosition({ 1.0f, 0.0f });

  btnMenuTile .setPosition({ 0.5f, 0.5f });
  btnMenuExtra.setPosition({ 0.5f, 0.5f });
  btnMenuDoor .setPosition({ 0.5f, 0.5f });

  btnMenuTile .setOffset({ -32, 0 });
  btnMenuExtra.setOffset({  32, 0 });

  // Button callbacks
  btnMenuTile.setMouseEnterCallback ([](Button& btn) { btn.getSprite().setClip({ 20, 0, 20, 20 }); });
  btnMenuTile.setMouseExitCallback  ([](Button& btn) { btn.getSprite().setClip({  0, 0, 20, 20 }); });

  btnMenuDoor.setMouseEnterCallback ([](Button& btn) { btn.getSprite().setClip({ 20, 0, 20, 20 }); });
  btnMenuDoor.setMouseExitCallback  ([](Button& btn) { btn.getSprite().setClip({  0, 0, 20, 20 }); });

  btnMenuExtra.setMouseEnterCallback([](Button& btn) { btn.getSprite().setClip({ 20, 0, 20, 20 }); });
  btnMenuExtra.setMouseExitCallback ([](Button& btn) { btn.getSprite().setClip({  0, 0, 20, 20 }); });

  // Change layout
  GuiManager::changeLayout(&gui);
}

void HangarScene::
unload() {
  // TODO: Unload images!
  GuiManager::popLayout();
}

void HangarScene::
draw() {
  // TODO IMPORTANT: Use GUI to draw shipbuilding!!!
  const Vec2 mousePos = Mouse::getPosition();

  const Vec2 WINDOW_SIZE = Game::getWindowSize();

  // TODO: Move grid constants to somewhere more global!
  const auto GRID_SIZE = ShipLayout::TileSize * ShipLayout::ShipSize;
  const Rect GRID_RECT = {
    WINDOW_SIZE.x / 2 - GRID_SIZE / 2, 135,
    GRID_SIZE, GRID_SIZE
  };

  // Grid
  Game::setDrawColor({ 64, 64, 64, 255 });
  Game::drawRect(GRID_RECT);

  Game::setDrawColor({ 48, 48, 48, 255 });
  for (int i = 0; i <= ShipLayout::ShipSize; ++i) {
    int y = i * ShipLayout::TileSize + GRID_RECT.y-1,
        x = i * ShipLayout::TileSize + GRID_RECT.x-1;
    Game::drawLine({ GRID_RECT.x - 1, y }, { GRID_RECT.x + GRID_RECT.w - 1, y });
    Game::drawLine({ x, GRID_RECT.y - 1 }, { x, GRID_RECT.y + GRID_RECT.h - 1 });
  }

  // Rooms
  for (auto room : rooms_)
    drawRoom(room.first);

  // Selected tiles
  Game::setDrawColor({ 128, 170, 128, 192 });
  for (int i = 0; i < ShipLayout::ShipSize; ++i) {
    for (int j = 0; j < ShipLayout::ShipSize; ++j) {
      if (selectedTiles_[i][j]) {
        int y = i * ShipLayout::TileSize + GRID_RECT.y,
            x = j * ShipLayout::TileSize + GRID_RECT.x;
        Game::drawRect({ x, y, ShipLayout::TileSize, ShipLayout::TileSize });
      }
    }
  }

  // Mouse over tile
  if (pointInsideRect(mousePos, GRID_RECT)) {
    Vec2 tileMouse = {
      (mousePos.x - GRID_RECT.x) / ShipLayout::TileSize,
      (mousePos.y - GRID_RECT.y) / ShipLayout::TileSize
    };

    int y = tileMouse.y * ShipLayout::TileSize + GRID_RECT.y,
        x = tileMouse.x * ShipLayout::TileSize + GRID_RECT.x;

    Game::setDrawColor({ 128, 224, 128, 192 });
    Game::drawRect({ x, y, ShipLayout::TileSize, ShipLayout::TileSize });
  }
}

void HangarScene::
update() {
  const Vec2 mousePos = Mouse::getPosition();
  const Vec2 WINDOW_SIZE = Game::getWindowSize();

  // TODO: Move grid constants to shipbuilding namespace
  const auto GRID_SIZE = ShipLayout::TileSize * ShipLayout::ShipSize;
  const Rect GRID_RECT = {
    WINDOW_SIZE.x / 2 - GRID_SIZE / 2, 135,
    GRID_SIZE, GRID_SIZE
  };

  if (pointInsideRect(mousePos, GRID_RECT)) {
    const Vec2 tileMouse = {
      (mousePos.x - GRID_RECT.x) / ShipLayout::TileSize,
      (mousePos.y - GRID_RECT.y) / ShipLayout::TileSize
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
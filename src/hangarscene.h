/**
  hangarscene.h
 */
#pragma once

#include <unordered_map>
#include <vector>

#include "util/types.h"
#include "scene.h"
#include "shiplayout.h"
//#include "sprite.h"

#include "widget.h"
#include "panel.h"
#include "image.h"
#include "button.h"

class HangarScene final : public Scene {
public:
  HangarScene();

  virtual void load() override;
  virtual void unload() override;
  virtual void draw() override;
  virtual void update() override;

private:
  bool createRoom();
  bool assignSystemToRoom(u32, u32);
  void drawRoom(u32);
  void removeTileFromRoom(int, int, u32);
  void setTileSelection(int, int, bool);
  int countConnectedComponents(const ShipLayout::ShipGrid&);

  u32 getTileRoom(int x, int y) { return tiles_[y][x]; }
  bool isTileSelected(int x, int y) { return selectedTiles_[y][x]; }

  struct Room {
    u32 system;
    std::vector<std::pair<int, int>> tiles;
  };

  ShipLayout::ShipGrid tiles_         = {};
  ShipLayout::ShipGrid selectedTiles_ = {};

  // TODO: Do this better!
  u32 roomCount_;
  std::unordered_map<u32, Room> rooms_;

  // GUI
  Panel gui;
  Image imgTitle, imgMenuBg;
  Button btnBack, btnStart, btnMenuTile, btnMenuDoor, btnMenuExtra;
};

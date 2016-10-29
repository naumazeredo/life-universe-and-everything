/**
  scene.h
  */
#pragma once

class Scene {
public:
  virtual void load()   = 0;
  virtual void unload() = 0;
  virtual void update() = 0;
  virtual void draw()   = 0;
};

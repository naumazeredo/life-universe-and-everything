/**
  scenemanager.cpp
  */
#include "scenemanager.h"

#include "scene.h"

namespace SceneManager {

namespace {

Scene* currentScene = nullptr;

}

void changeScene(Scene* scene) {
  if (currentScene)
    currentScene->unload();
  currentScene = scene;
  currentScene->load();
}

void update() {
  currentScene->update();
}

void draw() {
  currentScene->draw();
}

}

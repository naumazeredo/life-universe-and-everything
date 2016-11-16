/**
  guimanager.cpp
  */
#include "guimanager.h"

#include <vector>
#include "widget.h"

namespace GuiManager {

namespace {

std::vector<Widget*> layoutStack;

}

void update() {
  if (layoutStack.size() > 0)
    layoutStack.back()->update();
}

void draw() {
  for (const auto& layout : layoutStack)
    layout->draw();
}

void changeLayout(Widget* layout) {
  popLayout();
  pushLayout(layout);
}

void pushLayout(Widget* layout) {
  layoutStack.push_back(layout);
}

void popLayout() {
  // FIXME: pop_back throws when empty? if not remove verification
  if (layoutStack.size() > 0)
    layoutStack.pop_back();
}

}

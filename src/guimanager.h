/**
  guimanager.h
  */
#pragma once

class Widget;

namespace GuiManager {

void update();
void draw();

void changeLayout(Widget* /*layout*/);
void pushLayout(Widget* /*layout*/);
void popLayout();

}

/**
  panel.h
  */
#pragma once

#include "game.h"
#include "widget.h"

class Panel : public Widget {
protected:
  virtual void drawInternal  (Vec2f) const override {}
  virtual void updateInternal() override {}
};

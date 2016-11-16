/**
  image.h
  */
#pragma once

#include "widget.h"

class Image : public Widget {
public:
  inline Sprite  getSprite() const { return sprite_;  }
  inline Sprite& getSprite()       { return sprite_;  }

  inline void setSprite(Sprite sprite)  {
    sprite_ = sprite;
    setSize({ sprite_.getClip().w, sprite_.getClip().h });
  }

protected:
  virtual void drawInternal(Vec2f position) const override {
    sprite_.draw(position);
  }

  virtual void updateInternal() override {}

private:
  Sprite  sprite_;
};

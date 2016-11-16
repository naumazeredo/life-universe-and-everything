/**
  widget.h
  */
#pragma once

#include <vector>
#include <initializer_list>
#include "util/types.h"
#include "game.h"
#include "sprite.h"

class Widget {
public:
  Widget() = default;
  // TODO: Create more constructors to ease derived class construction?
  //Widget(Widget* /*parent*/, Sprite /*sprite*/);

  virtual ~Widget() {}

  // XXX: Don't add widget to multiple parents!
  void addChild(Widget* /*child*/);
  void addChildren(std::initializer_list<Widget*> /*children*/);

  inline Vec2f   getPivot    () const { return pivot_;                                            }
  inline Vec2f   getPosition () const { return getPosition(getParentPosition(), getParentSize()); }
  inline Vec2    getOffset   () const { return offset_;                                           }
  inline Vec2    getSize     () const { return fullscreen_ ? Game::getWindowSize() : size_;       }
  inline bool    getVisible  () const { return visible_;                                          }
  inline Widget* getParent   ()       { return parent_;                                           }
  inline Rect    getDrawRect () const {
    const Vec2 pos = getPosition();
    return { pos.x, pos.y, size_.x, size_.y };
  }

  inline void setPivot      (Vec2f pivot     ) { pivot_      = pivot;      }
  inline void setPosition   (Vec2f position  ) { position_   = position;   }
  inline void setOffset     (Vec2  offset    ) { offset_     = offset;     }
  inline void setSize       (Vec2  size      ) { size_       = size;       }
  inline void setFullscreen (bool  fullscreen) { fullscreen_ = fullscreen; }
  inline void setVisible    (bool  visible   ) { visible_    = visible;    }

  void update();
  void draw() const;

protected:
  virtual void drawInternal  (Vec2f /*position*/) const = 0;
  virtual void updateInternal() = 0;

private:
  // Private functions! Used internally by widget
  Vec2  getParentSize()     const;
  Vec2f getParentPosition() const;
  Vec2f getPosition(Vec2f parentPos, Vec2 parentSize) const;

  inline void setParent   (Widget* parent) { parent_ = parent; }

  void draw(Vec2f /*parentPos*/, Vec2 /*parentSize*/) const;

  // Widget attributes
  Widget* parent_   = nullptr;    // Parent widget
  std::vector<Widget*> children_; // Children widget (non-owning pointer!)

  // TODO: store global position/offset and use a dirty flag
  Vec2f pivot_      = { 0, 0 }; // Percentage position on widget
  Vec2f position_   = { 0, 0 }; // Percentage position on parent (no parent = whole screen)
  Vec2  offset_     = { 0, 0 }; // Offset (in pixels) from position
  Vec2  size_       = { 0, 0 }; // Size (in pixels)
  bool  visible_    = true;
  bool  fullscreen_ = false;
};

/**
  sprite.h
 */
#pragma once

#include <string>
#include "texture.h"
#include "util/types.h"
#include "anchor.h"

class Sprite {
public:
  Sprite() = default;
  Sprite(const std::string&);
  Sprite(const std::string&, Rect);
  Sprite(const std::string&, Anchor, Anchor);
  Sprite(const std::string&, Rect, Anchor, Anchor);
  Sprite(const std::string&, Rect, Vec2f, Anchor, Anchor);
  /*
  Sprite(const std::string&, Vec2f);
  Sprite(const std::string&, Vec2f, Rect);
  Sprite(Texture);
  Sprite(Texture, Vec2f);
  Sprite(Texture, Rect);
  Sprite(Texture, Vec2f, Rect);
  */

  inline Texture getTexture  () const { return texture_;  }
  inline Vec2f   getPosition () const { return position_; }
  inline Vec2f   getSize     () const { return size_;     }
  inline Rect    getClip     () const { return clip_;     }
  inline Vec2    getPivot    () const { return pivot_;    }
  Rect    getDrawRect () const;

  void setTexture(Texture);

  inline void setPosition (Vec2f  position) { position_ = position; }
  inline void setSize     (Vec2f  size)     { size_   = size;       }
  inline void setClip     (Rect   clip)     { clip_   = clip;       }
  inline void setAnchor   (Anchor anchor)   { anchor_ = anchor;     }
  inline void setPivot    (Vec2   pivot)    { pivot_  = pivot;      }
  inline void setPivot    (Anchor pivot)    {
    pivot_.x = pivot.h == HorizontalAnchor::Left ? 0 :
               pivot.h == HorizontalAnchor::Center ? (size_.x / 2) :
               size_.x;
    pivot_.y = pivot.v == VerticalAnchor::Top ? 0 :
               pivot.v == VerticalAnchor::Center ? (size_.y / 2) :
               size_.y;
  }

  void draw ();
  void draw (Vec2);

private:
  Texture texture_;

  // TODO: Sprite should have size and clip. position, pivot and anchor should be GUI stuff!
  Vec2f  position_ = { 0, 0 };
  Vec2f  size_     = { 0.0f, 0.0f };
  Rect   clip_     = { 0, 0, 0, 0 };
  Vec2   pivot_    = { 0, 0 };
  Anchor anchor_   = { VerticalAnchor::Top, HorizontalAnchor::Left };
};

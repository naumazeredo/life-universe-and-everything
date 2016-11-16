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
  Sprite(const std::string&, Vec2f);
  Sprite(const std::string&, Rect, Vec2f);

  inline Texture getTexture () const { return texture_; }
  inline Rect    getClip    () const { return clip_;    }
  inline Vec2    getPivot   () const { return pivot_;   }
  //inline Vec2f   getSize    () const { return size_;    }

  void setTexture(Texture /*texture*/);
  void setTexture(Texture /*texture*/, Rect /*clip*/);

  inline void setClip  (Rect  clip)  { clip_   = clip;  }
  inline void setPivot (Vec2f pivot) { pivot_  = pivot; }
  //inline void setSize  (Vec2f size)  { size_   = size;  }

  void draw (Vec2) const;

private:
  Texture texture_;

  Rect  clip_  = { 0, 0, 0, 0 }; // Texture clip
  Vec2f pivot_ = { 0, 0 };       // Pivot point (percentage)

  // XXX: Pixel perfect game. Should add sprite resizing?
  //Vec2f  size_     = { 0.0f, 0.0f };
};

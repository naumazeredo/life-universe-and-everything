/**
  anchor.h
  */
#pragma once

enum class VerticalAnchor   { Top,  Center, Bottom };
enum class HorizontalAnchor { Left, Center, Right  };
struct Anchor { VerticalAnchor v; HorizontalAnchor h; };

namespace Anchors {

const Anchor TopLeft     { VerticalAnchor::Top,    HorizontalAnchor::Left   };
const Anchor Top         { VerticalAnchor::Top,    HorizontalAnchor::Center };
const Anchor TopRight    { VerticalAnchor::Top,    HorizontalAnchor::Right  };

const Anchor Left        { VerticalAnchor::Center, HorizontalAnchor::Left   };
const Anchor Center      { VerticalAnchor::Center, HorizontalAnchor::Center };
const Anchor Right       { VerticalAnchor::Center, HorizontalAnchor::Right  };

const Anchor BottomLeft  { VerticalAnchor::Bottom, HorizontalAnchor::Left   };
const Anchor Bottom      { VerticalAnchor::Bottom, HorizontalAnchor::Center };
const Anchor BottomRight { VerticalAnchor::Bottom, HorizontalAnchor::Right  };

}

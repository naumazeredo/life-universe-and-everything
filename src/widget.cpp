/**
  widget.cpp
  */
#include "widget.h"

#include "game.h"

void Widget::
addChild(Widget* child) {
  children_.push_back(child);
  child->setParent(this);
}

void Widget::
addChildren(std::initializer_list<Widget*> children) {
  for (auto& child : children)
    addChild(child);
}

void Widget::
update() {
  if (!visible_)
    return;

  updateInternal();

  for (auto& child : children_)
    child->update();
}

void Widget::
draw(Vec2f parentPos, Vec2 parentSize) const {
  if (!visible_)
    return;

  const auto position = getPosition(parentPos, parentSize);
  drawInternal(position);

  for (const auto& child : children_) {
    child->draw(position, getSize());
  }
}

void Widget::
draw() const {
  draw(getParentPosition(), getParentSize());
}

Vec2 Widget::
getParentSize() const {
  return parent_ ? parent_->getSize() : Game::getWindowSize();
}

Vec2f Widget::
getParentPosition() const {
  return parent_ ? parent_->getPosition() : Vec2f { 0.0f, 0.0f };
}

Vec2f Widget::
getPosition(Vec2f parentPos, Vec2 parentSize) const {
  const auto size = getSize();
  return {
    parentPos.x + position_.x * parentSize.x - pivot_.x * size.x + offset_.x,
    parentPos.y + position_.y * parentSize.y - pivot_.y * size.y + offset_.y
  };
}

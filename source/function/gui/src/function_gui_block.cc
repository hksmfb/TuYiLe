#include "function_gui_block.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

void Block::SetTransform(corelayer::math::VecTransform trans) {
  trans_ = trans;
}

void Block::BindTrackPoint(std::string location) {
  auto dest = track_point_;
  if (location == std::string("center")) {
    dest = glm::vec2(0,0);
  } else if (location == std::string("topleft")) {
    dest = glm::vec2(-1,1);
  } else if (location == std::string("top")) {
    dest = glm::vec2(0,1);
  } else if (location == std::string("topright")) {
    dest = glm::vec2(1,1);
  } else if (location == std::string("left")) {
    dest = glm::vec2(-1,0);
  } else if (location == std::string("right")) {
    dest = glm::vec2(1,0);
  } else if (location == std::string("bottomleft")) {
    dest = glm::vec2(-1,-1);
  } else if (location == std::string("bottom")) {
    dest = glm::vec2(0,-1);
  } else if (location == std::string("bottomright")) {
    dest = glm::vec2(1,-1);
  }
  if (dest != track_point_) {
    offset_ = track_point_ - dest + offset_;
  }
}

void Block::SetTrackPoint(glm::vec2 point) {
  if (track_point_ == point) {
    return;
  }
  offset_ = track_point_ - point + offset_;
  track_point_ = point;
}

void Block::SetShape(ShapeBase* shape) {
  shape_ = shape;
}

ShapeBase* Block::GetShape() {
  return shape_;
}

void Block::AppendTrigger(TriggerBase* trigger) {
  trigger_.push_back(trigger);
}

void Block::SetTrigger(TriggerBase* trigger) {
  printf("todo: function::gui::Block::SetTrigger()\n");
}

void Block::DeleteTrigger(TriggerBase* trigger) {
  printf("todo: function::gui::Block::DeleteTrigger()\n");
}

void Block::DeleteTrigger(int index) {
  printf("todo: function::gui::Block::DeleteTrigger()\n");
}

void Block::AppendSubBlock(Block* block) {
  blocklist_.push_back(block);
}

void Block::CheckHover() {
  for (auto t : trigger_) {
    t->CheckHover();
  }
}

bool Block::IsHover() {
  for (auto t : trigger_) {
    if (t->IsHover()) {
      return true;
    }
  }
  return false;
}

void Block::OnHover(std::function<void()> func) {
  if (IsHover()) {
    func();
  }
}

void Block::OffHover(std::function<void()> func) {
  if (!IsHover()) {
    func();
  }
}

bool Block::IsClick() {
  if (IsHover()) {
    if (platformlayer::input::inputmanager->GetMouseKey(1).action) {
      return true;
    }
  }
  return false;
}

void Block::OnClick(std::function<void()> func) {
  if (IsClick()) {
    func();
  }
}

void Block::OffClick(std::function<void()> func) {
  if (!IsClick()) {
    func();
  }
}

}
}
}
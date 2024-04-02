#ifndef FUNCTION_GUI_TRIGGER_H_
#define FUNCTION_GUI_TRIGGER_H_

#include <iostream>
#include <functional>

#include "core_math_vectransform.h"
#include "platform_input_header.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

class TriggerBase {
 public:
  virtual bool IsHover() = 0;
  void OnHover(std::function<void()> func);
  void OffHover(std::function<void()> func);
  bool IsClick();
  void OnClick(std::function<void()> func);
  void OffClick(std::function<void()> func);
  glm::vec2 GetPos();
  void SetDraggable(bool b);
  void Drag();
  void Drop();
  void SetTransform(corelayer::math::VecTransform trans);
 private:
  glm::vec2 center_ {glm::vec2(0,0)};
  bool draggable_ {false};
  corelayer::math::VecTransform trans_ {};
  corelayer::math::VecTransform invtrans_ {};
};

class RectTrigger : public TriggerBase {
 public:
  bool IsHover() = 0;
 private:
  glm::vec2 size_ {glm::vec2(0,0)};
};

class CircleTrigger : public TriggerBase {
 public:
  bool IsHover() = 0;
 private:
  float radius_ {0};
};

}
}
}

#endif
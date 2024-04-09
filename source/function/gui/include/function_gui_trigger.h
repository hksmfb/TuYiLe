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
  virtual void CheckHover() = 0;
  bool IsHover();
  void OnHover(std::function<void()> func);
  void OffHover(std::function<void()> func);
  bool IsClick();
  void OnClick(std::function<void()> func);
  void OffClick(std::function<void()> func);
  void SetPos(float x, float y);
  void SetPos(glm::vec2 pos);
  glm::vec2 GetPos();
  void SetDraggable(bool b);
  void Drag();
  void Drop();
  void SetTransform(corelayer::math::VecTransform trans);
 protected:
  void RunFuncs();
  bool ishover_;
  corelayer::math::VecTransform trans_ {};
  corelayer::math::VecTransform invtrans_ {};
  std::function<void()> onhover_func_ {[](){}};
  std::function<void()> offhover_func_ {[](){}};
  std::function<void()> onclick_func_ {[](){}};
  std::function<void()> offclick_func_ {[](){}};
 private:
  glm::vec2 center_ {glm::vec2(0,0)};
  bool draggable_ {false};
};

class RectTrigger : public TriggerBase {
 public:
  RectTrigger();
  ~RectTrigger();
  void SetSize(float x, float y);
  void SetSize(glm::vec2 size);
  void CheckHover();
 private:
  glm::vec2 size_ {glm::vec2(0,0)};
};

class CircleTrigger : public TriggerBase {
 public:
  void CheckHover();
  bool IsHover();
 private:
  float radius_ {0};
};

}
}
}

#endif
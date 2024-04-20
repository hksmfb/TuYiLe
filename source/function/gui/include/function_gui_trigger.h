#ifndef FUNCTION_GUI_TRIGGER_H_
#define FUNCTION_GUI_TRIGGER_H_

#include <iostream>
#include <functional>

#include "core_math_vectransformstatic.h"
#include "platform_input_header.h"
#include "platform_window_manager.h"
#include "platform_rhi_rhi.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

class TriggerBase {
 public:
  virtual void CheckHover(glm::vec4& mousepos) = 0;
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
  void SetParentTrans(glm::mat4 trans);
  glm::mat4 GetParentTrans();
  corelayer::math::VecTransform& GetLocalTrans();
  glm::mat4 GetTransform();
 protected:
  void RunFuncs();
  bool ishover_;
  bool parent_trans_flag_ {true};
  glm::mat4 parent_trans_ {glm::mat4(1.0f)};
  corelayer::math::VecTransform local_trans_ {};
  glm::mat4 final_trans_ {glm::mat4(1.0f)};
  glm::mat4 invtrans_ {glm::mat4(1.0f)};
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
  void SetSize(float width, float height);
  void SetSize(glm::vec2 size);
  void CheckHover(glm::vec4& mousepos);
 private:
  glm::vec2 size_ {glm::vec2(0,0)};
};

class CircleTrigger : public TriggerBase {
 public:
  void CheckHover(glm::vec4& mousepos);
  bool IsHover();
 private:
  float radius_ {0};
};

}
}
}

#endif
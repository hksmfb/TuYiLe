#ifndef FUNCTION_GUI_TRIGGER_H_
#define FUNCTION_GUI_TRIGGER_H_

#include "core_math_vectransform.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

class TriggerBase {
 public:
  virtual bool OnHover() = 0;
  virtual bool OnClick() = 0;
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
  bool OnHover();
  bool OnClick();
 private:
  glm::vec2 size_ {glm::vec2(0,0)};
};

class CircleTrigger : public TriggerBase {
 public:
  bool OnHover();
  bool OnClick();
 private:
  float radius_ {0};
};

}
}
}

#endif
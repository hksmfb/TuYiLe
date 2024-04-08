#include "function_gui_trigger.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

bool TriggerBase::IsHover() {
  return ishover_;
}

void TriggerBase::OnHover(std::function<void()> func) {
  if (IsHover()) {
    func();
  }
}

void TriggerBase::OffHover(std::function<void()> func) {
  if (!IsHover()) {
    func();
  }
}

bool TriggerBase::IsClick() {
  if (IsHover()&&platformlayer::input::inputmanager->GetMouseKey(1).mods) {
    return true;
  }
  return false;
}

void TriggerBase::OnClick(std::function<void()> func) {
  if (IsClick()) {
    func();
  }
}

void TriggerBase::OffClick(std::function<void()> func) {
  if (!IsClick()) {
    func();
  }
}

glm::vec2 TriggerBase::GetPos() {
  return center_;
}

void TriggerBase::SetDraggable(bool b) {
  draggable_ = b;
}

void TriggerBase::Drag() {
#ifdef DEVMOD
std::cout << "function::gui::trigger::TriggerBase.Drag() in" <<std::endl;
#endif
  if (!draggable_) {
    return;
  }
  if (IsHover()) {
    if (platformlayer::input::inputmanager->GetMouseKey(1).action) {
      
    }
  }
#ifdef DEVMOD
std::cout << "function::gui::trigger::TriggerBase.Drag() out" <<std::endl;
#endif
}

void TriggerBase::Drop() {
  printf("todo: function::gui::TriggerBase.Drop()\n");
}

void TriggerBase::SetTransform(corelayer::math::VecTransform trans) {
  trans_ = trans;
}

RectTrigger::RectTrigger() {

}

RectTrigger::~RectTrigger() {

}

void RectTrigger::SetSize(float x, float y) {
  SetSize(glm::vec2(x, y));
}

void RectTrigger::SetSize(glm::vec2 size) {
  size_.x = size.x/2;
  size_.y = size.y/2;
  trans_.SetScale(glm::vec3(size,0));
  invtrans_ = trans_.inverse();
}

void RectTrigger::CheckHover() {
  glm::vec4 mousepos;
  mousepos.x = platformlayer::input::inputmanager->GetMousePosx();
  mousepos.y = platformlayer::input::inputmanager->GetMousePosy();
  mousepos.z = 0;
  mousepos.w = 1;
  mousepos = invtrans_.GetTransform()*mousepos;
  if (
    -1 <= mousepos.x && mousepos.x <= 1 &&
    -1 <= mousepos.y && mousepos.y <= 1
  ) {
    ishover_ = true;
    
  }
  ishover_ = false;

}

}
}
}
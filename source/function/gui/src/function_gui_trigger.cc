#include "function_gui_trigger.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

bool TriggerBase::IsHover() {
  return ishover_;
}

void TriggerBase::OnHover(std::function<void()> func) {
  onhover_func_ = func;
}

void TriggerBase::OffHover(std::function<void()> func) {
  offhover_func_ = func;
}

bool TriggerBase::IsClick() {
  if (ishover_&&platformlayer::input::inputmanager->GetMouseKey(1).action) {
    return true;
  }
  return false;
}

void TriggerBase::OnClick(std::function<void()> func) {
  onclick_func_ = func;
}

void TriggerBase::OffClick(std::function<void()> func) {
  offclick_func_ = func;
}

void TriggerBase::SetPos(float x, float y) {
  center_.x = x;
  center_.y = y;
}

void TriggerBase::SetPos(glm::vec2 pos) {
  center_ = pos;
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
  if (ishover_) {
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
  local_trans_ = trans;
  parent_trans_flag_ = true;
}

void TriggerBase::SetParentTrans(glm::mat4 trans) {
  parent_trans_ = trans;
  parent_trans_flag_ = true;
}

glm::mat4 TriggerBase::GetParentTrans() {
  return parent_trans_;
}

corelayer::math::VecTransform& TriggerBase::GetLocalTrans() {
  return local_trans_;
}

glm::mat4 TriggerBase::GetTransform() {
  if (parent_trans_flag_ || local_trans_.IsChange()) {
    final_trans_ = parent_trans_*local_trans_.GetTransform();
    invtrans_ = glm::inverse(final_trans_);
    parent_trans_flag_ = false;
  }
  return final_trans_;
}

void TriggerBase::RunFuncs() {
  if (IsHover()) {
    // printf("onhover\n");
    onhover_func_();
    if (IsClick()) {
      onclick_func_();
    }
  } else {
    // printf("offhover\n");
    offhover_func_();
    offclick_func_();
  }
}

RectTrigger::RectTrigger() {
  
}

RectTrigger::~RectTrigger() {

}

void RectTrigger::SetSize(float width, float height) {
  SetSize(glm::vec2(width, height));
}

void RectTrigger::SetSize(glm::vec2 size) {
  size_.x = size.x/2;
  size_.y = size.y/2;
  local_trans_.SetScale(glm::vec3(size,0));
}

void RectTrigger::CheckHover(glm::vec4& mousepos) {
  if (parent_trans_flag_ || local_trans_.IsChange()) {
    final_trans_ = parent_trans_*local_trans_.GetTransform();
    invtrans_ = glm::inverse(final_trans_);
    parent_trans_flag_ = false;
  }
  glm::vec4 pos = invtrans_*mousepos;
  if (
    -1 <= pos.x && pos.x <= 1 &&
    -1 <= pos.y && pos.y <= 1
  ) {
    ishover_ = true;
  } else {
    ishover_ = false;
  }
  // std::cout << mousepos.x << "," <<mousepos.y << std::endl;
  RunFuncs();
}

}
}
}
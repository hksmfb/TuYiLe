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
  trans_ = trans;
  invtrans_ = trans_.inverse();
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

void TriggerBase::SetViewportTrans(int windowwidth, int windowheight, int viewportwidth, int viewportheight) {
  corelayer::math::VecTransform viewport {};
  float wratio = viewportwidth/windowwidth;
  float hratio = viewportheight/windowheight;
  viewport.SetScale(wratio,hratio,1);
  viewport_trans_ = viewport.GetTransform();
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

void RectTrigger::CheckHover(glm::vec4& mousepos) {
  glm::vec4 pos = invtrans_.GetTransform()*mousepos;
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
#include "function_gui_trigger.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

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
    
  }
#ifdef DEVMOD
std::cout << "function::gui::trigger::TriggerBase.Drag() out" <<std::endl;
#endif
}

void TriggerBase::Drop() {
  printf("todo: function::gui::TriggerBase.Drop()\n");
}

}
}
}
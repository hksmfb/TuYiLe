#include "function_gui_button.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

Button::Button() {
  RectShape* rect = new RectShape();
  rect->SetSize(1,1);
  SetShape(rect);
  RectTrigger* trigger = new RectTrigger();
  trigger->SetSize(1,1);
  AppendTrigger(trigger);
  corelayer::math::VecTransform trans;
  trans.SetScale(0.2,0.1,1);
  SetTransform(trans);
}

Button::~Button() {
  DeleteTrigger(0);
}

}
}
}
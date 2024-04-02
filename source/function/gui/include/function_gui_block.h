#ifndef FUNCTION_GUI_BLOCK_H_
#define FUNCTION_GUI_BLOCK_H_

#include <vector>

#include "function_gui_shape.h"
#include "function_gui_trigger.h"
#include "core_math_vectransform.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

class Block {
 public:
  void SetShape(ShapeBase* shape);
  ShapeBase* GetShape();
  void SetTrigger(TriggerBase* trigger);
  void DeleteTrigger(TriggerBase* trigger);
  void DeleteTrigger(int index);
  TriggerBase* GetTrigger();
  void AppendSubBlock(Block* block);
  void PopSubBlock(Block* block);
  bool OnHover();
  bool OnClick();
  void Drag();
  void Drop();
 private:
  glm::vec3 center {glm::vec3(0,0,0)};
  ShapeBase* shape_ {nullptr};
  std::vector<TriggerBase*> trigger_ {};
  std::vector<Block*> blocklist_ {};
  std::vector<Block*> posorderlist_ {};
};

}
}
}

#endif
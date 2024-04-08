#ifndef FUNCTION_GUI_BLOCK_H_
#define FUNCTION_GUI_BLOCK_H_

#include <vector>
#include <functional>

#include "function_gui_shape.h"
#include "function_gui_trigger.h"
#include "core_math_vectransform.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

class Block {
 public:
  void SetTransform(corelayer::math::VecTransform trans);
  /**
   * @brief bind block to TrackPoint.
   * topleft,top,topright,left,center,right,bottomleft,bottom,bottomright.
   * offset = src - dest + offset
  */
  void BindTrackPoint(std::string location);
  void SetTrackPoint(glm::vec2 point);
  void SetShape(ShapeBase* shape);
  ShapeBase* GetShape();
  void AppendTrigger(TriggerBase* trigger);
  void SetTrigger(TriggerBase* trigger);
  void DeleteTrigger(TriggerBase* trigger);
  void DeleteTrigger(int index);
  TriggerBase* GetTrigger();
  void AppendSubBlock(Block* block);
  void PopSubBlock(Block* block);
  void CheckHover();
  bool IsHover();
  void OnHover(std::function<void()> func);
  void OffHover(std::function<void()> func);
  bool IsClick();
  void OnClick(std::function<void()> func);
  void OffClick(std::function<void()> func);
  void Drag();
  void Drop();
 private:
  float width {1.0f};
  float height {1.0f};
  float aspect_ratio_ {1.0f};
  corelayer::math::VecTransform trans_ {};
  glm::vec2 track_point_ {glm::vec2(0,0)};
  glm::vec2 offset_ {glm::vec2(0,0)};
  glm::vec3 center_ {glm::vec3(0,0,0)};
  ShapeBase* shape_ {nullptr};
  std::vector<TriggerBase*> trigger_ {};
  std::vector<Block*> blocklist_ {};
  std::vector<Block*> preorderlist_ {};
};

}
}
}

#endif
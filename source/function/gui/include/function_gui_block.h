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
  Block();
  ~Block();
  void SetTransform(corelayer::math::VecTransform trans);
  void SetPos(float x, float y);
  void SetPos(glm::vec2 pos);
  glm::vec3 GetPos();
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
  bool IsHover();
  void OnHover(std::function<void()> func);
  void OffHover(std::function<void()> func);
  bool IsClick();
  void OnClick(std::function<void()> func);
  void OffClick(std::function<void()> func);
  void Drag();
  void Drop();
  void CheckHover(glm::vec4& mousepos);
 private:
  float aspect_ratio_ {1.0f};
  corelayer::math::VecTransform trans_ {};
  glm::vec2 track_point_ {glm::vec2(0,0)};
  glm::vec2 offset_ {glm::vec2(0,0)};
  glm::vec3 center_ {glm::vec3(0,0,0)};
  std::vector<ShapeBase*> shape_ {};
  std::vector<TriggerBase*> trigger_ {};
  std::vector<Block*> blocklist_ {};
  std::vector<Block*> preorderlist_ {};
};

}
}
}

#endif
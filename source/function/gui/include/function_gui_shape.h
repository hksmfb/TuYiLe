#ifndef FUNCTION_GUI_SHAPE_H_
#define FUNCTION_GUI_SHAPE_H_

#include "function_render_rect2drender.h"
#include "function_render_meshrender.h"
#include "core_math_vectransform.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

class ShapeBase {
 public:
  void SetPos(glm::vec2 pos);
  glm::vec2 GetPos();
  void SetDepth(float depth);
  float GetDepth();
  void SetTransform(corelayer::math::VecTransform trans);
  void AppendTransform(corelayer::math::VecTransform trans);
  void SetParentTrans(glm::mat4 trans);
  glm::mat4 GetParentTrans();
  corelayer::math::VecTransform& GetLocalTrans();
  glm::mat4 GetTransform();
  render::RenderBase* GetRender();
 protected:
  render::MeshRender render_ {};
  bool parent_trans_flag_ {true};
  glm::mat4 parent_trans_ {glm::mat4(1.0f)};
  corelayer::math::VecTransform local_trans_ {};
  glm::mat4 final_trans_ {glm::mat4(1.0f)};
 private:
  glm::vec3 center_ {glm::vec3(0,0,0)};
};

class RectShape : public ShapeBase {
 public:
  RectShape();
  ~RectShape();
  void SetSize(float width, float height);
 private:
  glm::vec2 size_ {glm::vec2(0,0)};
};

}
}
}

#endif
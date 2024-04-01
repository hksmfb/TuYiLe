#ifndef FUNCTION_GUI_SHAPE_H_
#define FUNCTION_GUI_SHAPE_H_

#include "function_render_meshrender.h"
#include "core_math_vectransform.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

class ShapeBase {
 public:
  void SetPos(glm::vec2 pos);
  glm::vec2 GetPos();
 protected:
  render::MeshRender meshrender_ {};
  corelayer::math::VecTransform trans_ {};
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
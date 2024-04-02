#include "function_gui_shape.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

void ShapeBase::SetPos(glm::vec2 pos) {
  center_ = glm::vec3(pos,center_.z);
}

glm::vec2 ShapeBase::GetPos() {
  return glm::vec2(center_.x, center_.y);
}

RectShape::RectShape() {
  meshrender_.SetMesh(resourcelayer::manager::resourcemanager->GetMesh(1000));
  meshrender_.SetShader(resourcelayer::manager::resourcemanager->GetShader(3000));
}

RectShape::~RectShape() {

}

void RectShape::SetSize(float width, float height) {
  trans_.Scale(width, height, 0);
}

}
}
}
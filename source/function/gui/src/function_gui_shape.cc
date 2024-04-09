#include "function_gui_shape.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

void ShapeBase::SetTransform(corelayer::math::VecTransform trans) {
  trans_ = trans;
  meshrender_.SetTransform(trans_);
}

void ShapeBase::AppendTransform(corelayer::math::VecTransform trans) {
  trans_.Transform(trans);
  meshrender_.SetTransform(trans_);
}

corelayer::math::VecTransform ShapeBase::GetTransform() {
  return trans_;
}

render::RenderBase* ShapeBase::GetRender() {
  meshrender_.SetTransform(trans_);
  return &meshrender_;
}

void ShapeBase::SetPos(glm::vec2 pos) {
  center_ = glm::vec3(pos,center_.z);
  trans_.SetTranslate(center_);

}

glm::vec2 ShapeBase::GetPos() {
  return glm::vec2(center_.x, center_.y);
}

RectShape::RectShape() {
  meshrender_.SetMesh(1000);
  meshrender_.SetShader(3000);
}

RectShape::~RectShape() {

}

void RectShape::SetSize(float width, float height) {
  trans_.SetScale(width, height, 1);
}

}
}
}
#include "function_gui_shape.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

void ShapeBase::SetTransform(corelayer::math::VecTransform trans) {
  local_trans_ = trans;
  parent_trans_flag_ = true;
}

void ShapeBase::AppendTransform(corelayer::math::VecTransform trans) {
  // parent_trans_ = trans;
}

void ShapeBase::SetParentTrans(glm::mat4 trans) {
  parent_trans_ = trans;
  parent_trans_flag_ = true;
}

glm::mat4 ShapeBase::GetParentTrans() {
  return parent_trans_;
}

corelayer::math::VecTransform& ShapeBase::GetLocalTrans() {
  return local_trans_;
}

glm::mat4 ShapeBase::GetTransform() {
  if (parent_trans_flag_ || local_trans_.IsChange()) {
    final_trans_ = parent_trans_ * local_trans_.GetTransform();
    parent_trans_flag_ = false;
  }
  return final_trans_;
}

render::RenderBase* ShapeBase::GetRender() {
  render_.SetTransform(final_trans_);
  return &render_;
}

void ShapeBase::SetPos(glm::vec2 pos) {
  center_ = glm::vec3(pos,center_.z);
  local_trans_.SetTranslate(center_);
}

glm::vec2 ShapeBase::GetPos() {
  return glm::vec2(center_.x, center_.y);
}

void ShapeBase::SetDepth(float depth) {
  center_.z = depth;
}

float ShapeBase::GetDepth() {
  return center_.z;
}

RectShape::RectShape() {
  render_.SetMesh(1000);
  render_.SetShader(3000);
}

RectShape::~RectShape() {

}

void RectShape::SetSize(float width, float height) {
  local_trans_.SetScale(width, height, 1);
  parent_trans_flag_ = true;
}

}
}
}
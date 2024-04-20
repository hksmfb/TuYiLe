#include "core_math_vectransform.h"

#include <iostream>

namespace TuYiLe{
namespace corelayer {
namespace math{

VecTransform::VecTransform() {

}

VecTransform::~VecTransform() {
    
}

VecTransform& VecTransform::operator=(const VecTransform& trans) {
  rotate_ = trans.rotate_;
  scale_ = trans.scale_;
  translate_ = trans.translate_;
  transform_ = trans.transform_;
  changeflag_ = true;
  return *this;
}

VecTransform VecTransform::operator+(const VecTransform& trans) {
  VecTransform ret;
  ret.rotate_ = rotate_ + trans.rotate_;
  ret.scale_ = scale_ + trans.scale_;
  ret.translate_ = translate_ + trans.translate_;
  ret.transform_ = transform_ + trans.transform_;
  ret.changeflag_ = true;
  return ret;
}

VecTransform VecTransform::operator-(const VecTransform& trans) {
  VecTransform ret;
  ret.rotate_ = rotate_ - trans.rotate_;
  ret.scale_ = scale_ - trans.scale_;
  ret.translate_ = translate_ - trans.translate_;
  ret.transform_ = transform_ - trans.transform_;
  ret.changeflag_ = true;
  return ret;
}

VecTransform VecTransform::operator*(const float& f) {
  VecTransform ret;
  ret.rotate_ = rotate_ * f;
  ret.scale_ = scale_ * f;
  ret.translate_ = translate_ * f;
  ret.transform_ = transform_ * f;
  ret.changeflag_ = true;
  return ret;
}

bool VecTransform::operator==(const VecTransform& trans) {
  return (
    transform_ == trans.transform_&&
    rotate_ == trans.rotate_&&
    scale_ == trans.scale_&&
    translate_ == trans.translate_&&
    transform_ == trans.transform_);
}

VecTransform VecTransform::inverse() {
  VecTransform ret;
  ret.rotate_ = -rotate_;
  ret.scale_ = glm::vec3(1.0f/scale_.x, 1.0f/scale_.y, 1.0f/scale_.z);
  ret.translate_ = -translate_;
  ret.transform_ = glm::inverse(transform_);
  ret.changeflag_ = true;
  return ret;
}

void VecTransform::Reset() {
  changeflag_ = true;
  rotate_ = glm::vec3(0);
  scale_ = glm::vec3(1.0);
  translate_ = glm::vec3(0);
  transform_ = glm::mat4(1.0f);
}

// void VecTransform::apply(platformlayer::Shader* shader) {
//     shader->setMat4("transform", glm::value_ptr(transform));
//     shader->setMat4("projection", glm::value_ptr(projection));
//     shader->setMat4("view", glm::value_ptr(view));
//     // shader->setMat4("model", glm::value_ptr(model));
// }

void VecTransform::Rotate(float x, float y, float z) {
  rotate_[0] += x;
  rotate_[1] += y;
  rotate_[2] += z;
  changeflag_ = true;
}

void VecTransform::Rotate(floatvec3 rotate) {
  rotate_ += glm::vec3(rotate.x, rotate.y, rotate.z);
  changeflag_ = true;
}

void VecTransform::Rotate(const glm::vec3 rotate) {
  rotate_ += rotate;
  changeflag_ = true;
}

void VecTransform::SetRotate(const float x, const float y, const float z) {
  rotate_.x = x;
  rotate_.y = y;
  rotate_.z = z;
  changeflag_ = true;
}

void VecTransform::SetRotate(const floatvec3 rotate) {
  rotate_ = glm::vec3(rotate.x, rotate.y, rotate.z);
  changeflag_ = true;
}

void VecTransform::SetRotate(const glm::vec3 rotate) {
  rotate_ = rotate;
  changeflag_ = true;
}

void VecTransform::Scale(const float x, const float y, const float z) {
  scale_[0] += x;
  scale_[1] += y;
  scale_[2] += z;
  changeflag_ = true;
}

void VecTransform::Scale(const floatvec3 scale) {
  scale_ += glm::vec3(scale.x, scale.y, scale.z);
  changeflag_ = true;
}

void VecTransform::Scale(const glm::vec3 scale) {
  scale_ += scale;
  changeflag_ = true;
}

void VecTransform::SetScale(const float x, const float y, const float z) {
  scale_[0] = x;
  scale_[1] = y;
  scale_[2] = z;
  changeflag_ = true;
}

void VecTransform::SetScale(const floatvec3 scale) {
  scale_ = glm::vec3(scale.x, scale.y, scale.z);
  changeflag_ = true;
}

void VecTransform::SetScale(const glm::vec3 scale) {
  scale_ = glm::vec3(scale.x, scale.y, scale.z);
  changeflag_ = true;
}

void VecTransform::Translate(const float x, const float y, const float z) {
  translate_[0] += x;
  translate_[1] += y;
  translate_[2] += z;
  changeflag_ = true;
}

void VecTransform::Translate(const floatvec3 translate) {
  translate_ += glm::vec3(translate.x, translate.y, translate.z);
  changeflag_ = true;
}

void VecTransform::Translate(const glm::vec3 translate) {
  translate_ += translate;
  changeflag_ = true;
}

void VecTransform::SetTranslate(float x, float y, float z) {
  translate_[0] = x;
  translate_[1] = y;
  translate_[2] = z;
  changeflag_ = true;
}

void VecTransform::SetTranslate(const floatvec3 translate) {
  translate_ = glm::vec3(translate.x, translate.y, translate.z);
  changeflag_ = true;
}

void VecTransform::SetTranslate(const glm::vec3 translate) {
  translate_ = translate;
  changeflag_ = true;
}

void VecTransform::Transform(VecTransform trans) {
  other_transform_ = trans.GetTransform();
  changeflag_ = true;
}

bool VecTransform::IsChange() {
  return changeflag_;
}

glm::mat4 VecTransform::GetTransform() {
  if (changeflag_) {
    transform_ = glm::mat4(1.0f);
    transform_ = glm::translate(transform_, glm::vec3(translate_.x, translate_.y, translate_.z));
    transform_ = glm::rotate(transform_, glm::radians(rotate_.x), glm::vec3(1.0, 0.0, 0.0));
    transform_ = glm::rotate(transform_, glm::radians(rotate_.y), glm::vec3(0.0, 1.0, 0.0));
    transform_ = glm::rotate(transform_, glm::radians(rotate_.z), glm::vec3(0.0, 0.0, 1.0));
    transform_ = glm::scale(transform_, glm::vec3(scale_.x, scale_.y, scale_.z));
    changeflag_ = false;
    return transform_;
  } else {
    return transform_;
  }
}

}
}
}


#include "core_math_vectransformstatic.h"

namespace TuYiLe{
namespace corelayer {
namespace math{

VecTransformStatic::VecTransformStatic() {

}

VecTransformStatic::~VecTransformStatic() {

}

void VecTransformStatic::Apply() {
  transform_ = VecTransform::GetTransform();
}

glm::mat4 VecTransformStatic::GetTransform() {
  return transform_;
}
  

}
}
}
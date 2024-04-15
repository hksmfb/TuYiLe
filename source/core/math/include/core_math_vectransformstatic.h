#ifndef CORE_MATH_VECTRANSFORMSTATIC_H_
#define CORE_MATH_VECTRANSFORMSTATIC_H_

#include "core_math_vectransform.h"

namespace TuYiLe{
namespace corelayer {
namespace math{

class VecTransformStatic : VecTransform {
 public:
  VecTransformStatic();
  ~VecTransformStatic();
  void Apply();
  glm::mat4 GetTransform();
    
 private:
  bool static_ {false};
  glm::vec3 rotate_ {glm::vec3(0)};
  glm::vec3 scale_ {glm::vec3(1.0)};
  glm::vec3 translate_ {glm::vec3(0)};
  // bool is_transform_updated_;
  glm::mat4 other_transform_ {glm::mat4(1.0f)};
  glm::mat4 transform_ {glm::mat4(1.0f)};
};

}
}
}

#endif
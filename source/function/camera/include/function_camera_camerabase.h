#ifndef FUNCTION_CAMERA_CAMERABASE_H_
#define FUNCTION_CAMERA_CAMERABASE_H_

#include "core_math_vectransform.h"

namespace TuYiLe {
namespace functionlayer {
namespace camera {

class CameraBase {
 public:
  glm::mat4 GetView();
 private:
  glm::mat4 view_ {glm::mat4(1.0f)};
};

}
}
}

#endif
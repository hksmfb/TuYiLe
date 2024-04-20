#ifndef FUNCTION_RENDER_RECT2DRENDER_H_
#define FUNCTION_RENDER_RECT2DRENDER_H_

#include "function_render_renderbase.h"

namespace TuYiLe {
namespace functionlayer {
namespace render {

class Rect2DRender : public RenderBase {
 public:
  Rect2DRender();
  ~Rect2DRender();
  void SetTransform(corelayer::math::VecTransform trans);
  glm::mat4 GetTransform();
 private:
 
};

}
}
}

#endif
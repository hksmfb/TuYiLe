#ifndef PLATFORM_RHI_OPENGL_H_
#define PLATFORM_RHI_OPENGL_H_

#include <iostream>

#include "platform_rhi_glinterface.h"
#include "platform_rhi_shader.h"

namespace platformlayer {
namespace graphicinterface {
namespace opengl {

class OpenGLInterface : public GLInterface {
 public:
  OpenGLInterface();
  ~OpenGLInterface();
  void WindowInit();
  void ClearColor(int R, int G, int B, float Alpha);
  void SetViewport(int posx, int posy, int width, int height);
 private:
};

}
}
}

#endif
#ifndef PLATFORM_RHI_OPENGL_H_
#define PLATFORM_RHI_OPENGL_H_

#include "glad/glad.h"

#include "platform_rhi_glinterface.h"

namespace platformlayer {
namespace graphicinterface {
namespace opengl {

class OpenGLInterface : public GLInterface {
 public:
  OpenGLInterface();
  ~OpenGLInterface();
  void ClearColor(int R, int G, int B, float Alpha);
 private:
};

}
}
}

#endif
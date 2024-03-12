#include "platform_rhi_rhi.h"

namespace platformlayer {
namespace RHI {

graphicinterface::GLInterface* interface = nullptr;

void SetViewport(int posx, int posy, int width, int height) {
  interface->SetViewport(posx, posy, width, height);
}

void ClearColor(int R, int G, int B, float Alpha) {
  interface->ClearColor(R, G, B, Alpha);
}

Shader* CreateShader(std::string vertex, std::string fragment) {
  if (interface->GetInterfaceName() == std::string("OpenGL")) {
    return new graphicinterface::opengl::OpenGLShader(vertex, fragment);
  } else {
    return nullptr;
  }
}

}
}
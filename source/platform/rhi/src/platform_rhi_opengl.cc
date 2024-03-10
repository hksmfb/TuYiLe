#include "platform_rhi_opengl.h"

namespace platformlayer {
namespace graphicinterface {
namespace opengl {

OpenGLInterface::OpenGLInterface() {
  interfacename_ = "OpenGL";
}

OpenGLInterface::~OpenGLInterface() {

}

void OpenGLInterface::WindowInit(GLFWwindow* window) {
  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
  }
}

void OpenGLInterface::ClearColor(int R, int G, int B, float Alpha) {
  glClearColor(R/255.0f, G/255.0f, B/255.0f, Alpha);
  glClear(GL_COLOR_BUFFER_BIT);
}

}
}
}
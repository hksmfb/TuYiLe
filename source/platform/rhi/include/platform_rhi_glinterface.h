#ifndef PLATFORM_RHI_GLINTERFACE_H_
#define PLATFORM_RHI_GLINTERFACE_H_

#include <string>

#include "glad/glad.h"
#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

namespace platformlayer {
namespace graphicinterface {

class GLInterface {
 public:
  virtual void ClearColor(int R, int G, int B, float Alpha) = 0;
  virtual void WindowInit(GLFWwindow* window) = 0;
  std::string GetInterfaceName();
 protected:
  std::string interfacename_ {"Vulkan"};
 private:
};

}
}

#endif
#ifndef PLATFORM_RHI_GLINTERFACE_H_
#define PLATFORM_RHI_GLINTERFACE_H_

#include <string>

#include "glad/glad.h"
#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

#include "platform_window_manager.h"

namespace platformlayer {
namespace graphicinterface {

class GLInterface {
 public:
  virtual void WindowInit() = 0;
  virtual void ClearColor(int R, int G, int B, float Alpha) = 0;
  virtual void SetViewport(int posx, int posy, int width, int height) = 0;
  std::string GetInterfaceName();
 protected:
  std::string interfacename_ {"Vulkan"};
 private:
};

}
}

#endif
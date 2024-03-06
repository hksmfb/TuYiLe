#ifndef PLATFORM_RHI_GLINTERFACE_H_
#define PLATFORM_RHI_GLINTERFACE_H_

#include <string>

namespace platformlayer {
namespace graphicinterface {

class GLInterface {
 public:
  virtual void ClearColor(int R, int G, int B, float Alpha) = 0;
  std::string GetInterfaceName();
 protected:
  std::string interfacename_ {"Vulkan"};
 private:
};

}
}

#endif
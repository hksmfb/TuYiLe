#ifndef PLATFORM_RHI_INITIALIZER_H_
#define PLATFORM_RHI_INITIALIZER_H_

#include <string>

#include "platform_rhi_rhi.h"
#include "platform_rhi_opengl.h"
#include "platform_rhi_vulkan.h"

namespace platformlayer {
namespace graphicinterface {

class RhiInitializer {
 public:
  RhiInitializer(std::string graphiclib);
  ~RhiInitializer();
 private:
};

}
}

#endif
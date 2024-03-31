#include "platform_rhi_initializer.h"

namespace TuYiLe{
namespace platformlayer {
namespace graphicinterface {

RhiInitializer::RhiInitializer(std::string graphiclib) {
  if (graphiclib == std::string("OpenGL")) {
    RHI::interface = new opengl::OpenGLInterface();
  } else {
    RHI::interface = new vulkan::VulkanInterface();
  }
}

RhiInitializer::~RhiInitializer() {

}

}
}
}
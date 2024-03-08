#ifndef PLATFORM_RHI_VULKAN_INIT_H_
#define PLATFORM_RHI_VULKAN_INIT_H_

#include <vector>

#include "vulkan/vulkan.h"
#include "GLFW/glfw3.h"

namespace platformlayer {
namespace graphicinterface {
namespace vulkan {

class VulkanInit {
 public:
  VulkanInit();
  ~VulkanInit();
  VkInstance CreateInstance();
  VkPhysicalDevice SelectPhysicalDevice();
 private:
};

}
}
}

#endif
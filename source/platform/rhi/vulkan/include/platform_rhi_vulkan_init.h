#ifndef PLATFORM_RHI_VULKAN_INIT_H_
#define PLATFORM_RHI_VULKAN_INIT_H_

#include <iostream>
#include <vector>

#include "vulkan/vulkan.h"
#include "GLFW/glfw3.h"

#include "platform_rhi_vulkan_datatype.h"

namespace platformlayer {
namespace graphicinterface {
namespace vulkan {

class VulkanInit {
 public:
  VulkanInit();
  ~VulkanInit();
  void SetInstance(instanceinfo info, instance& ins);
//   VkPhysicalDevice SelectPhysicalDevice();
 private:
};

}
}
}

#endif
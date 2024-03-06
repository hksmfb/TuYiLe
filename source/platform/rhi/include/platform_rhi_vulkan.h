#ifndef PLATFORM_RHI_VULKAN_H_
#define PLATFORM_RHI_VULKAN_H_

#include <iostream>
#include <vector>

#include "vulkan/vulkan.h"
#include "glad/glad.h"
#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

#include "platform_rhi_glinterface.h"

namespace platformlayer {
namespace graphicinterface {
namespace vulkan {

class VulkanInterface : public GLInterface {
 public:
  VulkanInterface();
  ~VulkanInterface();
  void ClearColor(int R, int G, int B, float Alpha);
 private:
  void CreateInstance();
  void SelectPhysicalDevice();
  void CreateLogicalDevice();
  void FindQueueFamilies();
  VkInstance instance_ {VK_NULL_HANDLE};
  VkPhysicalDevice physical_device_ {VK_NULL_HANDLE};
  VkPhysicalDeviceProperties physical_device_properties_ {};
  VkPhysicalDeviceMemoryProperties physical_device_memory_properties_ {};
  std::vector<VkQueueFamilyProperties> queue_family_properties_;
};

}
}
}

#endif
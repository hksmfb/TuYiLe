#ifndef PLATFORM_RHI_VULKAN_DATATYPE_H_
#define PLATFORM_RHI_VULKAN_DATATYPE_H_

#include <string>
#include <vector>

#include "vulkan/vulkan.h"

namespace platformlayer {
namespace graphicinterface {
namespace vulkan {

struct instanceinfo {
  std::string name {""};
};

struct instance {
  VkInstance instance {VK_NULL_HANDLE};
  
  std::vector<VkQueueFamilyProperties> queue_family_properties;
  float queue_priorities {1.0f};
  VkDevice logical_device;
  VkQueue graphics_queue;
};

}
}
}

#endif
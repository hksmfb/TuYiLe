#include "platform_rhi_vulkan_init.h"

namespace platformlayer {
namespace graphicinterface {
namespace vulkan {

VulkanInit::VulkanInit() {

}

VulkanInit::~VulkanInit() {

}

VkInstance VulkanInit::CreateInstance() {
  VkInstance instance {VK_NULL_HANDLE};
  VkApplicationInfo appInfo{};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "Hello Triangle";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "No Engine";
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_API_VERSION_1_0;
  
  VkInstanceCreateInfo createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;

  uint32_t glfwExtensionCount = 0;
  const char** glfwExtensions;
  
  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  createInfo.enabledExtensionCount = glfwExtensionCount;
  createInfo.ppEnabledExtensionNames = glfwExtensions;

  createInfo.enabledLayerCount = 0;

  VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

  if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
    // std::cout << "failed to create instance!" << std::endl;
    // throw std::runtime_error("failed to create instance!");
  }

  uint32_t extensionCount = 0;
  vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
  std::vector<VkExtensionProperties> extensions(extensionCount);
  vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

  // std::cout << "available extensions:\n";
  // for (const auto& extension : extensions) {
  //   std::cout << '\t' << extension.extensionName << '\n';
  // }
  return instance;
}

VkPhysicalDevice VulkanInit::SelectPhysicalDevice() {}

}
}
}
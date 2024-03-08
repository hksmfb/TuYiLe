#include "platform_rhi_vulkan.h"

namespace platformlayer {
namespace graphicinterface {
namespace vulkan {

VulkanInterface::VulkanInterface() {
  interfacename_ = "Vulkan";
  VulkanInit init;
  instance_ = init.CreateInstance();
  // CreateInstance();
  SelectPhysicalDevice();
  CreateLogicalDevice();
  FindQueueFamilies();
}

VulkanInterface::~VulkanInterface() {

}

void VulkanInterface::ClearColor(int R, int G, int B, float Alpha) {

}

void VulkanInterface::CreateInstance() {
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

  VkResult result = vkCreateInstance(&createInfo, nullptr, &instance_);

  if (vkCreateInstance(&createInfo, nullptr, &instance_) != VK_SUCCESS) {
    std::cout << "failed to create instance!" << std::endl;
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

}

void VulkanInterface::SelectPhysicalDevice() {
  uint32_t deviceCount = 0;
  vkEnumeratePhysicalDevices(instance_, &deviceCount, nullptr);
  if (deviceCount == 0) {
    throw std::runtime_error("failed to find GPUs with Vulkan support!");
  }
  std::vector<VkPhysicalDevice> devices(deviceCount);
  vkEnumeratePhysicalDevices(instance_, &deviceCount, devices.data());

  for (const auto& device : devices) {
    if (device) {
      physical_device_ = device;
      break;
    }
  }
  if (physical_device_ == VK_NULL_HANDLE) {
    throw std::runtime_error("failed to find a suitable GPU!");
  }
  
  vkGetPhysicalDeviceProperties(physical_device_, &physical_device_properties_);
  vkGetPhysicalDeviceMemoryProperties(physical_device_, &physical_device_memory_properties_);
}

void VulkanInterface::FindQueueFamilies() {
  uint32_t queueFamilyPropertyCount;
  vkGetPhysicalDeviceQueueFamilyProperties(
    physical_device_,
    &queueFamilyPropertyCount,
    nullptr
  );
  queue_family_properties_.resize(queueFamilyPropertyCount);
  vkGetPhysicalDeviceQueueFamilyProperties(
    physical_device_,
    &queueFamilyPropertyCount,
    queue_family_properties_.data()
  );
}

void VulkanInterface::CreateLogicalDevice() {
  int indices {0};
  for (auto queuefamily : queue_family_properties_) {
    if (queuefamily.queueCount > 0 && (queuefamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)) {
      break;
    }
    ++indices;
  }
  VkDeviceQueueCreateInfo queueCreateInfo = {};
  queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
  queueCreateInfo.queueFamilyIndex = indices;
  queueCreateInfo.queueCount = 1;
  queueCreateInfo.pQueuePriorities = &queue_riorities_;

  VkPhysicalDeviceFeatures deviceFeatures = {};
  VkDeviceCreateInfo createInfo = {};
  createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
  createInfo.pQueueCreateInfos = &queueCreateInfo;
  createInfo.queueCreateInfoCount = 1;
  createInfo.pEnabledFeatures = &deviceFeatures;

  createInfo.enabledExtensionCount = 0;

  if (vkCreateDevice(physical_device_, &createInfo, nullptr, &logical_device_) != VK_SUCCESS) {
    throw std::runtime_error("failed to create logical device!");
  }

  vkGetDeviceQueue(logical_device_, indices, 0, &graphics_queue_);

}


}
}
}
#include "platform_rhi_vulkan_init.h"

namespace platformlayer {
namespace graphicinterface {
namespace vulkan {

VulkanInit::VulkanInit() {

}

VulkanInit::~VulkanInit() {

}

void VulkanInit::SetInstance(instanceinfo info, instance& ins) {
  VkApplicationInfo appInfo {};
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

  VkResult result = vkCreateInstance(&createInfo, nullptr, &ins.instance);

  if (vkCreateInstance(&createInfo, nullptr, &ins.instance) != VK_SUCCESS) {
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

  //----------------------------------physical device--------------------

  VkPhysicalDevice physical_device(VK_NULL_HANDLE);
  uint32_t deviceCount = 0;
  vkEnumeratePhysicalDevices(ins.instance, &deviceCount, nullptr);
  if (deviceCount == 0) {
    // throw std::runtime_error("failed to find GPUs with Vulkan support!");
  }
  std::vector<VkPhysicalDevice> devices(deviceCount);
  vkEnumeratePhysicalDevices(ins.instance, &deviceCount, devices.data());

  for (const auto& device : devices) {
    if (device) {
      physical_device = device;
      break;
    }
  }
  if (physical_device == VK_NULL_HANDLE) {
    // throw std::runtime_error("failed to find a suitable GPU!");
  }
  VkPhysicalDeviceProperties physical_device_properties {};
  vkGetPhysicalDeviceProperties(physical_device, &physical_device_properties);
  VkPhysicalDeviceMemoryProperties physical_device_memory_properties {};
  vkGetPhysicalDeviceMemoryProperties(physical_device, &physical_device_memory_properties);

  //-----------------------------queue families--------------------------

  uint32_t queue_family_property_count;
  vkGetPhysicalDeviceQueueFamilyProperties(
    physical_device,
    &queue_family_property_count,
    nullptr
  );
  ins.queue_family_properties.resize(queue_family_property_count);
  vkGetPhysicalDeviceQueueFamilyProperties(
    physical_device,
    &queue_family_property_count,
    ins.queue_family_properties.data()
  );

  //----------------------------logical device---------------------------------

  int indices(0);
  for (auto queuefamily : ins.queue_family_properties) {
    if (queuefamily.queueCount > 0 && (queuefamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)) {
      break;
    }
    ++indices;
  }
  VkDeviceQueueCreateInfo queueCreateInfo = {};
  queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
  queueCreateInfo.queueFamilyIndex = indices;
  queueCreateInfo.queueCount = 1;
  queueCreateInfo.pQueuePriorities = &ins.queue_priorities;

  VkPhysicalDeviceFeatures deviceFeatures = {};
  vkGetPhysicalDeviceFeatures(physical_device, &deviceFeatures);

  VkDeviceCreateInfo device_createInfo = {};
  device_createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
  device_createInfo.pQueueCreateInfos = &queueCreateInfo;
  device_createInfo.queueCreateInfoCount = 1;
  device_createInfo.pEnabledFeatures = &deviceFeatures;

  device_createInfo.enabledExtensionCount = 0;

  if (vkCreateDevice(physical_device, &device_createInfo, nullptr, &ins.logical_device) != VK_SUCCESS) {
    std::cout << "failed to create logical device!" << std::endl;
    // throw std::runtime_error("failed to create logical device!");
  }

  vkGetDeviceQueue(ins.logical_device, indices, 0, &ins.graphics_queue);

}

// VkPhysicalDevice VulkanInit::SelectPhysicalDevice() {

// }
  
}
}
}
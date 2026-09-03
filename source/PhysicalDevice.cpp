#include "PhysicalDevice.hpp"

namespace invoker::setup_vulkan::physical_device 
{

  VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

  void pickPhysicalDevice(VkInstance instance)     // pass by value because we only want to read not modify
  {
      uint32_t deviceCount = 0;
      
      vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

      if(deviceCount == 0) 
          throw std::runtime_error("failed to find GPUs with Vulkan support");

      std::vector<VkPhysicalDevice> devices(deviceCount);
      std::multimap<int, VkPhysicalDevice> candidates;

      vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());
      
      for(const auto& device : devices)
      {
         int score = rateDeviceSuitable(device);
         candidates.emplace(score, device);
      }
      
      if(candidates.rbegin() -> first > 0)
          physicalDevice = candidates.rbegin()->second;
      else
         throw std::runtime_error("failed to find a suitable GPU!");

  }

namespace 
{

  bool isDeviceSuitable(VkPhysicalDevice device)
  {
      VkPhysicalDeviceProperties deviceProperties;
      VkPhysicalDeviceFeatures deviceFeatures;
      vkGetPhysicalDeviceProperties(device, &deviceProperties);
      vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

      return deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU &&
                                          deviceFeatures.geometryShader;
  
  }

  int rateDeviceSuitable(VkPhysicalDevice device)
  {
      int score = 0;

      VkPhysicalDeviceProperties deviceProperties;
      VkPhysicalDeviceFeatures deviceFeatures;
      vkGetPhysicalDeviceProperties(device, &deviceProperties);
      vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

 
      if(deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
        score += 1000;
      
      score += deviceProperties.limits.maxImageDimension2D;

      if (!deviceFeatures.geometryShader) 
          return 0;

      return score;
  }

}

}

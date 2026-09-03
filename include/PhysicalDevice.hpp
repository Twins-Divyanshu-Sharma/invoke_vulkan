#ifndef H_PHYSICAL_DEVICE_H
#define H_PHYSICAL_DEVICE_H

#include <vulkan/vulkan.hpp>
#include <map>

namespace invoker::setup_vulkan::physical_device
{
    extern VkPhysicalDevice physicalDevice;
    void pickPhysicalDevice(VkInstance);
}

#endif

#ifndef H_LOGICAL_DEVICE_H
#define H_LOGICAL_DEVICE_H

#include "QueueFamily.hpp"

namespace invoker::setup_vulkan::logical_device
{
    void create(VkPhysicalDevice& physicalDevice);
    void cleanup();

    extern VkDevice device;
    extern VkQueue graphicsQueue;
}

#endif

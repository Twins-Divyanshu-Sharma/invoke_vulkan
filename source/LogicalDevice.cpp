#include "LogicalDevice.hpp"

namespace invoker::vulkan_setup::logical_device
{
    VkDevice device = VK_NULL_HANDLE;
    VkQueue graphicsQueue = VK_NULL_HANDLE;

    void create(VkPhysicalDevice& physicalDevice)
    {
        float queuePriority = 1.0f;

        invoker::setup_vulkan::QueueFamilyIndicies indices =
            invoker::setup_vulkan::findQueueFamilies(physicalDevice);

        VkDeviceQueueCreateInfo queueCreateInfo
        {
            .sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
            .queueFamilyIndex = indices.graphicsFamily.value(),
            .queueCount = 1,
            .pQueuePriorities = &queuePriority
        };

        VkPhysicalDeviceFeatures deviceFeatures{};

        VkDeviceCreateInfo createInfo
        {
            .sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
            .queueCreateInfoCount = 1,
            .pQueueCreateInfos = &queueCreateInfo,
            .pEnabledFeatures = &deviceFeatures
        };

        if (vkCreateDevice(physicalDevice, &createInfo, nullptr,&device) != VK_SUCCESS)
            throw std::runtime_error("Failed to create logical device!");
        

        vkGetDeviceQueue(device, indices.graphicsFamily.value(), 0, &graphicsQueue);
    }

    void cleanup()
    {
        if (device != VK_NULL_HANDLE)
        {
            vkDestroyDevice(device, nullptr);
            device = VK_NULL_HANDLE;
        }
    }
}

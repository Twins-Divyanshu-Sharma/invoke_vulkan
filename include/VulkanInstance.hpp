#ifndef H_VULKAN_CREATE_INSTANCE_H
#define H_VULKAN_CREATE_INSTANCE_H

#include "vk_mem_alloc.h"

#include <iostream>
#include <string>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vulkan/vulkan.hpp>

namespace invoker::setup_vulkan::vulkanInstance
{
    VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData
    );

    void create();
    void cleanup();

    extern VkInstance instance;
}

#endif

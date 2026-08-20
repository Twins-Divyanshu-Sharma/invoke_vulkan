#include "VulkanInstance.hpp"

#include <stdexcept>
#include <vector>

namespace invoker::setup_vulkan::vulkanInstance
{
    VkInstance instance = VK_NULL_HANDLE;

    VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData
    )
    {
        if (messageSeverity >= VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT)
        {
            std::cerr<< "Validation layer: "<< pCallbackData->pMessage << std::endl;
        }

        return VK_FALSE;
    }

    void create()
    {
        VkApplicationInfo appInfo
        {
            .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
            .pApplicationName = "Invoke Vulkan",
            .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
            .pEngineName = "Invoker",
            .engineVersion = VK_MAKE_VERSION(1, 0, 0),
            .apiVersion = VK_API_VERSION_1_1
        };

        std::vector<const char*> requestedExtensions
        {
            VK_EXT_DEBUG_UTILS_EXTENSION_NAME
        };

        uint32_t extensionsCount = 0;

        const char** glfwExtensions =
            glfwGetRequiredInstanceExtensions(&extensionsCount);

        for (uint32_t i = 0; i < extensionsCount; ++i)
        {
            requestedExtensions.push_back(glfwExtensions[i]);
        }

        std::vector<const char*> requestedLayers
        {
            "VK_LAYER_KHRONOS_validation"
        };

        VkDebugUtilsMessengerCreateInfoEXT debugInfo
        {
            .sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,

            .messageSeverity =
                VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
                VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
                VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT,

            .messageType =
                VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
                VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
                VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT,

            .pfnUserCallback = debugCallback
        };

        VkInstanceCreateInfo instCreateInfo
        {
            .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
            .pNext = &debugInfo,
            .pApplicationInfo = &appInfo,
            .enabledLayerCount = static_cast<uint32_t>(requestedLayers.size()),
            .ppEnabledLayerNames = requestedLayers.data(),
            .enabledExtensionCount = static_cast<uint32_t>(requestedExtensions.size()),
            .ppEnabledExtensionNames = requestedExtensions.data()
        };

        if (vkCreateInstance(&instCreateInfo,nullptr,&instance) != VK_SUCCESS)
        {
            throw std::runtime_error("Failed to create Vulkan instance");
        }
    }

    void cleanup()
    {
        if (instance != VK_NULL_HANDLE)
        {
            vkDestroyInstance(instance, nullptr);
            instance = VK_NULL_HANDLE;
        }
    }
}

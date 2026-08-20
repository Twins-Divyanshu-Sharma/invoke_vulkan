#include "VulkanCommence.hpp"

VulkanCommence::VulkanCommence()
{

    VkApplicationInfo appInfo 
    {
        .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pApplicationName = "Invoke Vulkan",
        .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
        .pEngineName = "Invoker",
        .engineVersion = VK_MAKE_VERSION(1, 0, 0),
        .apiVersion = VK_API_VERSION_1_1,
      
    };

      std::vector<const char *> requestedExtensions
      {
        VK_EXT_DEBUG_UTILS_EXTENSION_NAME
      };

      uint32_t extensionsCount = 0;
      const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&extensionsCount);

      for(int i=0; i<extensionsCount; i++)
        requestedExtensions.push_back(glfwExtensions[i]);

      std::vector<const char *> requestedLayers
      {
        "VK_LAYER_KHRONOS_validation"
      };

      VkDebugUtilsMessengerCreateInfoEXT debugInfo
      {
          .sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,
          .messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | 
                              VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
                              VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT,
          .messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
                          VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT,
          .pfnUserCallback = debugCallback
    
      };

      VkInstanceCreateInfo instCreateInfo
      {
          .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
          .pNext = &debugInfo,
          .pApplicationInfo = &appInfo,
          .enabledLayerCount = static_cast<uint32_t>(requestedLayers.size()),
          .enabledExtensionCount = static_cast<uint32_t>(requestedExtensions.size()),
          .ppEnabledExtensionNames = requestedLayers.data(),
          .ppEnabledExtensionNames = requestedExtensions.data(),
      };

      if( vkCreateInstance(&instCreateInfo, nullptr, &instance) != VK_SUCCESS ) 
          throw std::runtime_error("failed to create vulkan instance :( "); 

}

VKAPI_ATTR VkBool32 VKAPI_CALL VulkanCommence::debugCallback (
      VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
      VkDebugUtilsMessageTypeFlagsEXT messageType,
      const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
      void *pUserData
  )
{
      if(messageSeverity >= VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT )
          std::cerr << "Validation layer" << pCallbackData->pMessage << std::endl;

  return VK_FALSE;
}

VulkanCommence& VulkanCommence::getTheOnlyObject()
{
    static VulkanCommence instance;
    return instance;
}

VulkanCommence::~VulkanCommence(){
    vkDestroyInstance(instance, nullptr);

}

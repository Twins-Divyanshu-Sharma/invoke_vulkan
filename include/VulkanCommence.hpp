#ifndef H_VULKAN_COMMENCE_H
#define H_VULKAN_COMMENCE_H

#include "vk_mem_alloc.h"
#include <iostream>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.hpp>
#include <string>

class VulkanCommence
{

private: 
  
  VkInstance instance;

  VulkanCommence();
  ~VulkanCommence(); 

static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback (
      VkDebugUtilsMessageSeverityFlagBitsEXT,
      VkDebugUtilsMessageTypeFlagsEXT,
      const VkDebugUtilsMessengerCallbackDataEXT *,
      void *pUserData
  );

public: 
   VulkanCommence(const VulkanCommence&) = delete;
   VulkanCommence& operator=(const VulkanCommence&) = delete;
   VulkanCommence(VulkanCommence&&) = delete;
   VulkanCommence& operator=(VulkanCommence&&) = delete;
  
   static VulkanCommence& getTheOnlyObject();
};

#endif

#ifndef H_VULKAN_COMMENCE_H
#define H_VULKAN_COMMENCE_H

#include "VulkanInstance.hpp"
#include "Window.hpp"
#include "PhysicalDevice.hpp"
#include "LogicalDevice.hpp"

class VulkanCommence
{

private: 
  VulkanCommence();
  ~VulkanCommence(); 

  invoker::Window win;

public: 
   VulkanCommence(const VulkanCommence&) = delete;
   VulkanCommence& operator=(const VulkanCommence&) = delete;
   VulkanCommence(VulkanCommence&&) = delete;
   VulkanCommence& operator=(VulkanCommence&&) = delete;
  
   static VulkanCommence& getTheOnlyObject();
};

#endif

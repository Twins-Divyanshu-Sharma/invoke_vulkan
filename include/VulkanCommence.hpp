#ifndef H_VULKAN_COMMENCE_H
#define H_VULKAN_COMMENCE_H

class VulkanCommence
{

private: 
  VulkanCommence();
  ~VulkanCommence(); 

public: 
   VulkanCommence(const VulkanCommence&) = delete;
   VulkanCommence& operator=(const VulkanCommence&) = delete;
   VulkanCommence(VulkanCommence&&) = delete;
   VulkanCommence& operator=(VulkanCommence&&) = delete;
  
   static VulkanCommence& getTheOnlyObject();
};

#endif

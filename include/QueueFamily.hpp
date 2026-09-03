#ifndef H_QUEUE_FAMILY_H
#define H_QUEUE_FAMILY_H

#include <optional>
#include <vulkan/vulkan.hpp>

namespace invoker::setup_vulkan::queue_family
{
   struct QueueFamilyIndicies
   {
        std::optional<uint32_t> graphicsFamily;
        bool isComplete(); 
    };
  
    QueueFamilyIndicies findQueueFamilies(VkPhysicalDevice device);
    
}


#endif

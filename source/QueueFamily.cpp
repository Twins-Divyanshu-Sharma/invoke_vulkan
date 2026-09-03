#include "QueueFamily.hpp"

namespace invoker::setup_vulkan::queue_family
{

    bool QueueFamilyIndicies::isComplete()
    {
       return graphicsFamily.has_value();
    }

    QueueFamilyIndicies findQueueFamilies(VkPhysicalDevice device)
    {
        QueueFamilyIndicies indices;
        uint32_t queueFamilyCount = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);
        std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());
       
        int i = 0;
        for(const auto& queueFamily : queueFamilies)
        {
            if(queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
                indices.graphicsFamily = i;

            if(indices.isComplete())
                break;

            i++;
        }

        return indices;
    }

    namespace
    {

        bool isDeviceSuitable(VkPhysicalDevice device)
        {
            QueueFamilyIndicies indices = findQueueFamilies(device);
            return indices.isComplete();
        }

    }

}

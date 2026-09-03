#include "VulkanCommence.hpp"

VulkanCommence::VulkanCommence()
{
   using namespace invoker::setup_vulkan;

   vulkanInstance::create();
   physical_device::pickPhysicalDevice(vulkanInstance::instance);
   logical_device::create(physical_device::physicalDevice);
}



VulkanCommence& VulkanCommence::getTheOnlyObject()
{
    static VulkanCommence singleton;
    return singleton;
}

VulkanCommence::~VulkanCommence(){
}

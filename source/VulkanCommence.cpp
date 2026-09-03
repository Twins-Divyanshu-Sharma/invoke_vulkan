#include "VulkanCommence.hpp"

VulkanCommence::VulkanCommence()
{
    
}



VulkanCommence& VulkanCommence::getTheOnlyObject()
{
    static VulkanCommence instance;
    return instance;
}

VulkanCommence::~VulkanCommence(){
}

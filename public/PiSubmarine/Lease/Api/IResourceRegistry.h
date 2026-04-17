#pragma once

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Lease/Api/ResourceDescriptor.h"

namespace PiSubmarine::Lease::Api
{
    class IResourceRegistry
    {
    public:
        virtual ~IResourceRegistry() = default;

        [[nodiscard]] virtual Error::Api::Result<void> RegisterResource(const ResourceDescriptor& resource) = 0;
        [[nodiscard]] virtual Error::Api::Result<ResourceDescriptor> GetResource(const ResourceId& resourceId) const = 0;
    };
}

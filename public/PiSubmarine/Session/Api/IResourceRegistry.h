#pragma once

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Session/Api/ResourceDescriptor.h"

namespace PiSubmarine::Session::Api
{
    class IResourceRegistry
    {
    public:
        virtual ~IResourceRegistry() = default;

        [[nodiscard]] virtual Error::Api::Result<void> RegisterResource(const ResourceDescriptor& resource) = 0;
        [[nodiscard]] virtual Error::Api::Result<ResourceDescriptor> GetResource(const ResourceId& resourceId) const = 0;
    };
}

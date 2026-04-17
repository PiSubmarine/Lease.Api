#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Lease/Api/IResourceRegistry.h"

namespace PiSubmarine::Lease::Api
{
    class IResourceRegistryMock : public IResourceRegistry
    {
    public:
        MOCK_METHOD((Error::Api::Result<void>), RegisterResource, (const ResourceDescriptor& resource), (override));
        MOCK_METHOD((Error::Api::Result<ResourceDescriptor>), GetResource, (const ResourceId& resourceId), (const, override));
    };
}

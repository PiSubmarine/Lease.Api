#pragma once

#include "PiSubmarine/Lease/Api/Identifiers.h"
#include "PiSubmarine/Lease/Api/LeasePolicy.h"

namespace PiSubmarine::Lease::Api
{
    struct ResourceDescriptor
    {
        ResourceId Id;
        LeasePolicy Policy;

        [[nodiscard]] bool operator==(const ResourceDescriptor&) const = default;
    };
}

#pragma once

#include "PiSubmarine/Lease/Api/Identifiers.h"

namespace PiSubmarine::Lease::Api
{
    struct LeaseRequest
    {
        ResourceId Resource;

        [[nodiscard]] bool operator==(const LeaseRequest&) const = default;
    };
}

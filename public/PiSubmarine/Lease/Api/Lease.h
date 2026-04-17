#pragma once

#include <chrono>

#include "PiSubmarine/Lease/Api/Identifiers.h"

namespace PiSubmarine::Lease::Api
{
    struct Lease
    {
        LeaseId Id;
        ResourceId Resource;
        std::chrono::milliseconds Duration{0};

        [[nodiscard]] bool operator==(const Lease&) const = default;
    };
}

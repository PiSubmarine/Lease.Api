#pragma once

#include <cstddef>
#include <vector>

namespace PiSubmarine::Lease::Api
{
    struct LeaseSecret
    {
        std::vector<std::byte> Value;

        [[nodiscard]] bool operator==(const LeaseSecret&) const = default;
    };
}

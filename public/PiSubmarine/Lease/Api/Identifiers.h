#pragma once

#include <string>

namespace PiSubmarine::Lease::Api
{
    struct ResourceId
    {
        std::string Value;

        [[nodiscard]] bool operator==(const ResourceId&) const = default;
    };

    struct LeaseId
    {
        std::string Value;

        [[nodiscard]] bool operator==(const LeaseId&) const = default;
    };
}

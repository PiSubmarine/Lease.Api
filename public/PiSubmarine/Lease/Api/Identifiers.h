#pragma once

#include <string>

namespace PiSubmarine::Lease::Api
{
	// TODO Split into ResourceId.h and LeaseId.h
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

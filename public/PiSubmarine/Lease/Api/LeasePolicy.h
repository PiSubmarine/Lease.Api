#pragma once

#include <chrono>
#include <cstddef>
#include <optional>

namespace PiSubmarine::Lease::Api
{
    struct LeasePolicy
    {
        std::optional<std::size_t> MaxLeases = 1;
        std::chrono::milliseconds LeaseDuration{0};

        [[nodiscard]] bool operator==(const LeasePolicy&) const = default;
    };
}

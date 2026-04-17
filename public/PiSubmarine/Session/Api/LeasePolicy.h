#pragma once

#include <chrono>
#include <cstddef>

namespace PiSubmarine::Session::Api
{
    enum class SharingPolicy
    {
        Exclusive,
        Shared
    };

    struct LeasePolicy
    {
        SharingPolicy Sharing = SharingPolicy::Exclusive;
        std::size_t MaxLeases = 1;
        std::chrono::milliseconds LeaseDuration{0};
        std::chrono::milliseconds HeartbeatTimeout{0};
        bool RequiresActivation = true;

        [[nodiscard]] bool operator==(const LeasePolicy&) const = default;
    };
}

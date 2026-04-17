#pragma once

#include <chrono>

#include "PiSubmarine/Session/Api/Identifiers.h"

namespace PiSubmarine::Session::Api
{
    struct Lease
    {
        LeaseId Id;
        SessionId Session;
        ResourceId Resource;
        std::chrono::milliseconds Duration{0};

        [[nodiscard]] bool operator==(const Lease&) const = default;
    };
}

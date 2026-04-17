#pragma once

#include "PiSubmarine/Session/Api/Identifiers.h"

namespace PiSubmarine::Session::Api
{
    struct LeaseRequest
    {
        SessionId Session;
        ResourceId Resource;

        [[nodiscard]] bool operator==(const LeaseRequest&) const = default;
    };
}

#pragma once

#include <string>

namespace PiSubmarine::Session::Api
{
    struct SessionId
    {
        std::string Value;

        [[nodiscard]] bool operator==(const SessionId&) const = default;
    };

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

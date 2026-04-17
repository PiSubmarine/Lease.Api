#pragma once

namespace PiSubmarine::Session::Api
{
    struct LeaseValidation
    {
        bool IsValid = false;

        [[nodiscard]] bool operator==(const LeaseValidation&) const = default;
    };
}

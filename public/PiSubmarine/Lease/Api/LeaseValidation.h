#pragma once

namespace PiSubmarine::Lease::Api
{
    struct LeaseValidation
    {
        bool IsValid = false;

        [[nodiscard]] bool operator==(const LeaseValidation&) const = default;
    };
}

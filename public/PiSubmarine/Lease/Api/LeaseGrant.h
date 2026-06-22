#pragma once

#include "PiSubmarine/Lease/Api/Lease.h"
#include "PiSubmarine/Lease/Api/LeaseSecret.h"

namespace PiSubmarine::Lease::Api
{
    struct LeaseGrant
    {
        Lease GrantedLease;
        LeaseSecret Secret;

        [[nodiscard]] bool operator==(const LeaseGrant&) const = default;
    };
}

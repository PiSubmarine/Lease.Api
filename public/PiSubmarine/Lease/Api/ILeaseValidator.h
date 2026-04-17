#pragma once

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Lease/Api/Identifiers.h"
#include "PiSubmarine/Lease/Api/LeaseValidation.h"

namespace PiSubmarine::Lease::Api
{
    class ILeaseValidator
    {
    public:
        virtual ~ILeaseValidator() = default;

        [[nodiscard]] virtual Error::Api::Result<LeaseValidation> ValidateLease(
            const LeaseId& leaseId,
            const ResourceId& resourceId) const = 0;
    };
}

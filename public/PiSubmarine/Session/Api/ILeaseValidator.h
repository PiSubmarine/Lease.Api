#pragma once

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Session/Api/Identifiers.h"
#include "PiSubmarine/Session/Api/LeaseValidation.h"

namespace PiSubmarine::Session::Api
{
    class ILeaseValidator
    {
    public:
        virtual ~ILeaseValidator() = default;

        [[nodiscard]] virtual Error::Api::Result<LeaseValidation> ValidateLease(
            const LeaseId& leaseId,
            const SessionId& sessionId,
            const ResourceId& resourceId) const = 0;
    };
}

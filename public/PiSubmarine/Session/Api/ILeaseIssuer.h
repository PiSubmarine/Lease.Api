#pragma once

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Session/Api/Identifiers.h"
#include "PiSubmarine/Session/Api/Lease.h"
#include "PiSubmarine/Session/Api/LeaseRequest.h"

namespace PiSubmarine::Session::Api
{
    class ILeaseIssuer
    {
    public:
        virtual ~ILeaseIssuer() = default;

        [[nodiscard]] virtual Error::Api::Result<Lease> AcquireLease(const LeaseRequest& request) = 0;
        [[nodiscard]] virtual Error::Api::Result<Lease> RenewLease(const LeaseId& leaseId) = 0;
        [[nodiscard]] virtual Error::Api::Result<void> ReleaseLease(const LeaseId& leaseId) = 0;
    };
}

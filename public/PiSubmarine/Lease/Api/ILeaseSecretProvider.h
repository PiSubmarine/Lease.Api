#pragma once

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Lease/Api/Identifiers.h"
#include "PiSubmarine/Lease/Api/LeaseSecret.h"

namespace PiSubmarine::Lease::Api
{
    class ILeaseSecretProvider
    {
    public:
        virtual ~ILeaseSecretProvider() = default;

        [[nodiscard]] virtual Error::Api::Result<LeaseSecret> GetLeaseSecret(const LeaseId& leaseId) const = 0;
    };
}

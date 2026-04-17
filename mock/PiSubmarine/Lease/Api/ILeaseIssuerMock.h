#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Lease/Api/ILeaseIssuer.h"

namespace PiSubmarine::Lease::Api
{
    class ILeaseIssuerMock : public ILeaseIssuer
    {
    public:
        MOCK_METHOD((Error::Api::Result<Lease>), AcquireLease, (const LeaseRequest& request), (override));
        MOCK_METHOD((Error::Api::Result<Lease>), RenewLease, (const LeaseId& leaseId), (override));
        MOCK_METHOD((Error::Api::Result<void>), ReleaseLease, (const LeaseId& leaseId), (override));
    };
}

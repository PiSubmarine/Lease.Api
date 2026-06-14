#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Lease/Api/ILeaseSecretProvider.h"

namespace PiSubmarine::Lease::Api
{
    class ILeaseSecretProviderMock : public ILeaseSecretProvider
    {
    public:
        MOCK_METHOD((Error::Api::Result<LeaseSecret>), GetLeaseSecret, (const LeaseId& leaseId), (const, override));
    };
}

#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Lease/Api/ILeaseValidator.h"

namespace PiSubmarine::Lease::Api
{
    class ILeaseValidatorMock : public ILeaseValidator
    {
    public:
        MOCK_METHOD(
            (Error::Api::Result<LeaseValidation>),
            ValidateLease,
            (const LeaseId& leaseId, const ResourceId& resourceId),
            (const, override));
    };
}

#include <gtest/gtest.h>

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Lease/Api/ErrorCode.h"
#include "PiSubmarine/Lease/Api/ILeaseIssuerMock.h"
#include "PiSubmarine/Lease/Api/ILeaseValidatorMock.h"
#include "PiSubmarine/Lease/Api/IResourceRegistryMock.h"
#include "PiSubmarine/Error/Api/ErrorCondition.h"
#include "PiSubmarine/Error/Api/MakeError.h"

namespace PiSubmarine::Lease::Api
{
    TEST(LeaseApiMockTest, LeaseIssuerReturnsConfiguredLease)
    {
        ILeaseIssuerMock leaseIssuerMock;
        const LeaseRequest request{
            .Resource = ResourceId{"control-main"}};
        const Lease expectedLease{
            .Id = LeaseId{"lease-1"},
            .Resource = ResourceId{"control-main"},
            .Duration = std::chrono::seconds(3)};

        EXPECT_CALL(leaseIssuerMock, AcquireLease(request))
            .WillOnce(testing::Return(Error::Api::Result<Lease>(expectedLease)));

        const auto result = leaseIssuerMock.AcquireLease(request);

        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(result.value(), expectedLease);
    }

    TEST(LeaseApiMockTest, LeaseValidatorReturnsConfiguredValidation)
    {
        ILeaseValidatorMock leaseValidatorMock;
        const LeaseId leaseId{"lease-1"};
        const ResourceId resourceId{"video-main"};
        constexpr LeaseValidation expectedValidation{
            .IsValid = true};

        EXPECT_CALL(leaseValidatorMock, ValidateLease(leaseId, resourceId))
            .WillOnce(testing::Return(Error::Api::Result<LeaseValidation>(expectedValidation)));

        const auto result = leaseValidatorMock.ValidateLease(leaseId, resourceId);

        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(result.value(), expectedValidation);
    }

    TEST(LeaseApiMockTest, ResourceRegistryReturnsConfiguredDescriptor)
    {
        IResourceRegistryMock resourceRegistryMock;
        const ResourceId resourceId{"telemetry-main"};
        const ResourceDescriptor expectedDescriptor{
            .Id = resourceId,
            .Policy = LeasePolicy{
                .MaxLeases = std::nullopt,
                .LeaseDuration = std::chrono::seconds(5)}};

        EXPECT_CALL(resourceRegistryMock, GetResource(resourceId))
            .WillOnce(testing::Return(Error::Api::Result<ResourceDescriptor>(expectedDescriptor)));

        const auto result = resourceRegistryMock.GetResource(resourceId);

        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(result.value(), expectedDescriptor);
    }

    TEST(LeaseApiMockTest, ResourceRegistryCanReturnDomainError)
    {
        IResourceRegistryMock resourceRegistryMock;
        const ResourceId resourceId{"missing"};
        const auto expectedError = Error::Api::MakeError(
            Error::Api::ErrorCondition::ContractError,
            make_error_code(ErrorCode::ResourceNotFound));

        EXPECT_CALL(resourceRegistryMock, GetResource(resourceId))
            .WillOnce(testing::Return(std::unexpected(expectedError)));

        const auto result = resourceRegistryMock.GetResource(resourceId);

        ASSERT_FALSE(result.has_value());
        EXPECT_EQ(result.error(), expectedError);
    }
}

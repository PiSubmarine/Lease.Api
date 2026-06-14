#include <gtest/gtest.h>

#include <cstddef>

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Lease/Api/ErrorCode.h"
#include "PiSubmarine/Lease/Api/ILeaseIssuerMock.h"
#include "PiSubmarine/Lease/Api/ILeaseSecretProviderMock.h"
#include "PiSubmarine/Lease/Api/ILeaseValidatorMock.h"
#include "PiSubmarine/Lease/Api/IResourceRegistryMock.h"
#include "PiSubmarine/Error/Api/ErrorCondition.h"
#include "PiSubmarine/Error/Api/MakeError.h"

namespace PiSubmarine::Lease::Api
{
    TEST(LeaseApiMockTest, LeaseIssuerReturnsConfiguredLeaseGrant)
    {
        ILeaseIssuerMock leaseIssuerMock;
        const LeaseRequest request{
            .Resource = ResourceId{"control-main"}};
        const LeaseGrant expectedGrant{
            .Lease = Lease{
                .Id = LeaseId{"lease-1"},
                .Resource = ResourceId{"control-main"},
                .Duration = std::chrono::seconds(3)},
            .Secret = LeaseSecret{
                .Value = {std::byte{0x10}, std::byte{0x20}}}};

        EXPECT_CALL(leaseIssuerMock, AcquireLease(request))
            .WillOnce(testing::Return(Error::Api::Result<LeaseGrant>(expectedGrant)));

        const auto result = leaseIssuerMock.AcquireLease(request);

        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(result.value(), expectedGrant);
    }

    TEST(LeaseApiMockTest, LeaseSecretProviderReturnsConfiguredSecret)
    {
        ILeaseSecretProviderMock leaseSecretProviderMock;
        const LeaseId leaseId{"lease-1"};
        const LeaseSecret expectedSecret{
            .Value = {std::byte{0xAA}, std::byte{0xBB}}};

        EXPECT_CALL(leaseSecretProviderMock, GetLeaseSecret(leaseId))
            .WillOnce(testing::Return(Error::Api::Result<LeaseSecret>(expectedSecret)));

        const auto result = leaseSecretProviderMock.GetLeaseSecret(leaseId);

        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(result.value(), expectedSecret);
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

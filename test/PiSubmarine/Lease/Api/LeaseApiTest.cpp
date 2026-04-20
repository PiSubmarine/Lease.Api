#include <gtest/gtest.h>

#include "PiSubmarine/Lease/Api/ErrorCode.h"
#include "PiSubmarine/Lease/Api/LeasePolicy.h"
#include "PiSubmarine/Lease/Api/ResourceDescriptor.h"

namespace PiSubmarine::Lease::Api
{
    TEST(LeaseApiTest, ResourceDescriptorStoresLeasePolicy)
    {
        const ResourceDescriptor descriptor{
            .Id = ResourceId{"video-main"},
            .Policy = LeasePolicy{
                .MaxLeases = std::nullopt,
                .LeaseDuration = std::chrono::seconds(5)}};

        ASSERT_FALSE(descriptor.Policy.MaxLeases.has_value());
        EXPECT_EQ(descriptor.Id.Value, "video-main");
        EXPECT_EQ(descriptor.Policy.MaxLeases, std::nullopt);
        EXPECT_EQ(descriptor.Policy.LeaseDuration, std::chrono::seconds(5));
    }

    TEST(LeaseApiTest, ErrorCodeProducesExpectedMessage)
    {
        const auto errorCode = make_error_code(ErrorCode::LeaseLimitReached);

        EXPECT_EQ(errorCode.category().name(), std::string("PiSubmarine.Lease.Api"));
        EXPECT_EQ(errorCode.message(), std::string("resource lease limit has been reached"));
    }
}

#include <gtest/gtest.h>

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
                .LeaseDuration = std::chrono::seconds(5),
                .RequiresActivation = true}};

        ASSERT_FALSE(descriptor.Policy.MaxLeases.has_value());
        EXPECT_EQ(descriptor.Id.Value, "video-main");
        EXPECT_EQ(descriptor.Policy.MaxLeases, std::nullopt);
        EXPECT_TRUE(descriptor.Policy.RequiresActivation);
    }
}

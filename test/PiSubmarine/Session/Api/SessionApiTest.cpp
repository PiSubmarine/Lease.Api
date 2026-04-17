#include <gtest/gtest.h>

#include "PiSubmarine/Session/Api/LeasePolicy.h"
#include "PiSubmarine/Session/Api/ResourceDescriptor.h"

namespace PiSubmarine::Session::Api
{
    TEST(SessionApiTest, ResourceDescriptorStoresOpaqueActivationData)
    {
        const ResourceDescriptor descriptor{
            .Id = ResourceId{"video-main"},
            .Policy = LeasePolicy{
                .Sharing = SharingPolicy::Shared,
                .MaxLeases = 0,
                .LeaseDuration = std::chrono::seconds(5),
                .HeartbeatTimeout = std::chrono::seconds(2),
                .RequiresActivation = true},
            .Activation = ActivationDescriptor{"grpc://127.0.0.1:50051/video-main"}};

        ASSERT_TRUE(descriptor.Activation.has_value());
        EXPECT_EQ(descriptor.Activation->Value, "grpc://127.0.0.1:50051/video-main");
        EXPECT_EQ(descriptor.Policy.Sharing, SharingPolicy::Shared);
    }
}

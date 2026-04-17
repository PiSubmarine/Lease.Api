#pragma once

#include <optional>

#include "PiSubmarine/Session/Api/ActivationDescriptor.h"
#include "PiSubmarine/Session/Api/Identifiers.h"
#include "PiSubmarine/Session/Api/LeasePolicy.h"

namespace PiSubmarine::Session::Api
{
    struct ResourceDescriptor
    {
        ResourceId Id;
        LeasePolicy Policy;
        std::optional<ActivationDescriptor> Activation;

        [[nodiscard]] bool operator==(const ResourceDescriptor&) const = default;
    };
}

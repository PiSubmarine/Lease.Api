#pragma once

#include <string>

namespace PiSubmarine::Session::Api
{
    struct ActivationDescriptor
    {
        std::string Value;

        [[nodiscard]] bool operator==(const ActivationDescriptor&) const = default;
    };
}

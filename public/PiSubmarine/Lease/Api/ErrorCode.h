#pragma once

#include <system_error>

namespace PiSubmarine::Lease::Api
{
    enum class ErrorCode
    {
        InvalidResourceId = 1,
        InvalidLeaseId,
        InvalidLeaseSecret,
        InvalidLeaseDuration,
        InvalidMaxLeases,
        ResourceAlreadyRegistered,
        ResourceNotFound,
        LeaseLimitReached,
        LeaseNotFound,
        LeaseExpired,
        LeaseIdGenerationFailed,
        LeaseSecretGenerationFailed
    };

    [[nodiscard]] std::error_code make_error_code(ErrorCode errorCode) noexcept;
}

namespace std
{
    template<>
    struct is_error_code_enum<PiSubmarine::Lease::Api::ErrorCode> : true_type
    {
    };
}

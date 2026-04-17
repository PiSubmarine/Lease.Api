#include "PiSubmarine/Lease/Api/ErrorCode.h"

namespace PiSubmarine::Lease::Api
{
    namespace
    {
        class ErrorCategory final : public std::error_category
        {
        public:
            [[nodiscard]] const char* name() const noexcept override
            {
                return "PiSubmarine.Lease.Api";
            }

            [[nodiscard]] std::string message(const int condition) const override
            {
                switch (static_cast<ErrorCode>(condition))
                {
                case ErrorCode::InvalidResourceId:
                    return "resource id must not be empty";

                case ErrorCode::InvalidLeaseId:
                    return "lease id must not be empty";

                case ErrorCode::InvalidLeaseDuration:
                    return "lease duration must be positive";

                case ErrorCode::InvalidMaxLeases:
                    return "max leases must be positive when specified";

                case ErrorCode::ResourceAlreadyRegistered:
                    return "resource is already registered";

                case ErrorCode::ResourceNotFound:
                    return "resource was not found";

                case ErrorCode::LeaseLimitReached:
                    return "resource lease limit has been reached";

                case ErrorCode::LeaseNotFound:
                    return "lease was not found";

                case ErrorCode::LeaseExpired:
                    return "lease has expired";

                case ErrorCode::LeaseIdGenerationFailed:
                    return "failed to generate a secure lease id";
                }

                return "unknown lease api error";
            }
        };

        [[nodiscard]] const std::error_category& GetErrorCategory() noexcept
        {
            static const ErrorCategory Category;
            return Category;
        }
    }

    [[nodiscard]] std::error_code make_error_code(const ErrorCode errorCode) noexcept
    {
        return {static_cast<int>(errorCode), GetErrorCategory()};
    }
}

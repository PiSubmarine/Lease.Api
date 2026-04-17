include("${_build_cmake_local}")

message("Adding library: ${PISUBMARINE_MODULE_NAME}")
add_library(${PISUBMARINE_MODULE_NAME}
        PiSubmarine/Lease/Api/ErrorCode.cpp
        "../public/PiSubmarine/Lease/Api/Identifiers.h"
        "../public/PiSubmarine/Lease/Api/ErrorCode.h"
        "../public/PiSubmarine/Lease/Api/ILeaseIssuer.h"
        "../public/PiSubmarine/Lease/Api/ILeaseValidator.h"
        "../public/PiSubmarine/Lease/Api/IResourceRegistry.h"
        "../public/PiSubmarine/Lease/Api/Lease.h"
        "../public/PiSubmarine/Lease/Api/LeasePolicy.h"
        "../public/PiSubmarine/Lease/Api/LeaseRequest.h"
        "../public/PiSubmarine/Lease/Api/LeaseValidation.h"
        "../public/PiSubmarine/Lease/Api/ResourceDescriptor.h"
)
target_include_directories(${PISUBMARINE_MODULE_NAME} PUBLIC "../public")
PiSubmarineInitTarget(${PISUBMARINE_MODULE_NAME})

PiSubmarineAddDependency("https://github.com/PiSubmarine/Error.Api" "")
target_link_libraries(${PISUBMARINE_MODULE_NAME} PUBLIC PiSubmarine.Error.Api)

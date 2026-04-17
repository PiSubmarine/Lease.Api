include("${_build_cmake_local}")

message("Adding library: ${PISUBMARINE_MODULE_NAME}")
add_library(${PISUBMARINE_MODULE_NAME} INTERFACE
        "../public/PiSubmarine/Session/Api/ActivationDescriptor.h"
        "../public/PiSubmarine/Session/Api/Identifiers.h"
        "../public/PiSubmarine/Session/Api/ILeaseIssuer.h"
        "../public/PiSubmarine/Session/Api/ILeaseValidator.h"
        "../public/PiSubmarine/Session/Api/IResourceRegistry.h"
        "../public/PiSubmarine/Session/Api/Lease.h"
        "../public/PiSubmarine/Session/Api/LeasePolicy.h"
        "../public/PiSubmarine/Session/Api/LeaseRequest.h"
        "../public/PiSubmarine/Session/Api/LeaseValidation.h"
        "../public/PiSubmarine/Session/Api/ResourceDescriptor.h"
)
target_include_directories(${PISUBMARINE_MODULE_NAME} INTERFACE "../public")
PiSubmarineInitTarget(${PISUBMARINE_MODULE_NAME})

PiSubmarineAddDependency("https://github.com/PiSubmarine/Error.Api" "")
target_link_libraries(${PISUBMARINE_MODULE_NAME} INTERFACE PiSubmarine.Error.Api)

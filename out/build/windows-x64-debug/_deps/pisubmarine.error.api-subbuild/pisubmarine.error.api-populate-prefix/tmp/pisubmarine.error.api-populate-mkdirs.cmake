# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarine.error.api-src")
  file(MAKE_DIRECTORY "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarine.error.api-src")
endif()
file(MAKE_DIRECTORY
  "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarine.error.api-build"
  "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarine.error.api-subbuild/pisubmarine.error.api-populate-prefix"
  "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarine.error.api-subbuild/pisubmarine.error.api-populate-prefix/tmp"
  "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarine.error.api-subbuild/pisubmarine.error.api-populate-prefix/src/pisubmarine.error.api-populate-stamp"
  "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarine.error.api-subbuild/pisubmarine.error.api-populate-prefix/src"
  "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarine.error.api-subbuild/pisubmarine.error.api-populate-prefix/src/pisubmarine.error.api-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarine.error.api-subbuild/pisubmarine.error.api-populate-prefix/src/pisubmarine.error.api-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarine.error.api-subbuild/pisubmarine.error.api-populate-prefix/src/pisubmarine.error.api-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

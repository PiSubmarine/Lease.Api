# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarinebuild-src")
  file(MAKE_DIRECTORY "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarinebuild-src")
endif()
file(MAKE_DIRECTORY
  "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarinebuild-build"
  "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarinebuild-subbuild/pisubmarinebuild-populate-prefix"
  "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarinebuild-subbuild/pisubmarinebuild-populate-prefix/tmp"
  "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarinebuild-subbuild/pisubmarinebuild-populate-prefix/src/pisubmarinebuild-populate-stamp"
  "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarinebuild-subbuild/pisubmarinebuild-populate-prefix/src"
  "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarinebuild-subbuild/pisubmarinebuild-populate-prefix/src/pisubmarinebuild-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarinebuild-subbuild/pisubmarinebuild-populate-prefix/src/pisubmarinebuild-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Software/GitHub/PiSubmarine/Session.Api/out/build/windows-x64-debug/_deps/pisubmarinebuild-subbuild/pisubmarinebuild-populate-prefix/src/pisubmarinebuild-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

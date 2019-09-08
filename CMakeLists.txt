cmake_minimum_required(VERSION 3.2)

project(psscpp VERSION 0.0.0)

option(BUILD_TEST "Whether to build unit tests" ON)

set(CPP_STANDARD "11" CACHE STRING "C++ Standard")
set(CMAKE_CXX_STANDARD ${CPP_STANDARD})

# Set Flags
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Werror -g ")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Werror -O3")

if (BUILD_TEST)
  #find_package(GTest REQUIRED)
  enable_testing()
  add_subdirectory(test)
endif()

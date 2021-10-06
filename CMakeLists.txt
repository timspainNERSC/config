cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_STANDARD 11)

project(config)

set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(Boost COMPONENTS program_options REQUIRED)

# Build the main model
add_subdirectory(src)

# Testing
#if (NOT(CMAKE_BUILD_TYPE STREQUAL "Release"))
#    add_subdirectory(test)
#endif()

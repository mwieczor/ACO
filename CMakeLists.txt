# yout project name here
project(cmake_template_with_tests)

# test for requered cmake version
cmake_minimum_required(VERSION 3.0)

add_definitions( -std=c++1y )
if ( CMAKE_BUILD_TYPE STREQUAL "Release" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo" OR CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
    add_definitions( --pedantic -Wall -Wextra )
    add_definitions( -march=native  )
endif() # CMAKE_BUILD_TYPE STREQUAL "Release"

# add directory containing external libs (tests / other libraries etc)
add_subdirectory(extern)

# your application code goes here
add_subdirectory(src)

# your tests goes in this directory
add_subdirectory(tests)

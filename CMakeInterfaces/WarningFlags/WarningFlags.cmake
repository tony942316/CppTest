cmake_minimum_required(VERSION 3.28)

add_library(WarningFlags INTERFACE)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(WarningFlags INTERFACE
        /W4)
else ()
    target_compile_options(WarningFlags INTERFACE
        -Wall -Wextra -Wpedantic -Wconversion)
endif()

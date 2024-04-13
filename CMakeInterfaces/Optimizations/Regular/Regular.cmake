cmake_minimum_required(VERSION 3.28)

add_library(EQX-Regular INTERFACE)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(EQX-Regular INTERFACE
        /O2t)
else ()
    target_compile_options(EQX-Regular INTERFACE
        -O3)
endif()

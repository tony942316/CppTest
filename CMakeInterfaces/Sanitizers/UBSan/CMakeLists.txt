cmake_minimum_required(VERSION 3.28)

add_library(UBSan INTERFACE)
target_compile_options(UBSan INTERFACE -fsanitize=undefined)
target_link_options(UBSan INTERFACE -fsanitize=undefined)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_options(UBSan INTERFACE
        -static-libubsan)
endif()

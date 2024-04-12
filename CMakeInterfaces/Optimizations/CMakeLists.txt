cmake_minimum_required(VERSION 3.28)

add_subdirectory(FastMath)
add_subdirectory(NoExceptions)
add_subdirectory(NoRTTI)
add_subdirectory(Regular)

add_library(Optimizations INTERFACE)
target_link_libraries(Optimizations INTERFACE
    FastMath NoExceptions NoRTTI Regular)

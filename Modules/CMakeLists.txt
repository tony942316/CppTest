cmake_minimum_required(VERSION 3.28)

add_library(GMF INTERFACE) # Global Module Flags

add_library(IOStream STATIC)
target_sources(IOStream
    PUBLIC FILE_SET CXX_MODULES FILES
        IOStream.cpp)
target_compile_features(IOStream PUBLIC cxx_std_20)
target_link_libraries(IOStream PUBLIC GMF)

set_target_properties(IOStream PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

add_library(Regular STATIC)
target_sources(Regular
    PUBLIC FILE_SET CXX_MODULES FILES
        Regular.cpp)
target_sources(Regular PRIVATE Implementation.cpp)
target_compile_features(Regular PUBLIC cxx_std_20)
target_link_libraries(Regular PUBLIC GMF IOStream)

set_target_properties(Regular PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

add_library(Partition STATIC)
target_sources(Partition
    PUBLIC FILE_SET CXX_MODULES FILES
        Partition.cpp
        Partition-Implementation.cpp
        Partition-Interface.cpp)
target_compile_features(Partition PUBLIC cxx_std_20)
target_link_libraries(Partition PUBLIC GMF IOStream)

set_target_properties(Partition PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

add_executable(Modules)
target_sources(Modules PRIVATE Main.cpp)
target_compile_features(Modules PRIVATE cxx_std_20)
target_link_libraries(Modules PRIVATE Regular Partition)

target_link_libraries(GMF INTERFACE EQX-Warnings)
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_link_libraries(GMF INTERFACE
        "$<$<CONFIG:Debug>:EQX-DebugSymbols;EQX-Sanitizers>"
        "$<$<CONFIG:Release>:EQX-Optimizations>")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_link_libraries(GMF INTERFACE
        EQX-DebugSymbols EQX-Sanitizers)
else ()
    target_link_libraries(GMF INTERFACE
        EQX-DebugSymbols EQX-ASan EQX-LSan)
endif()

set_target_properties(Modules PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

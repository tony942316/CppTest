cmake_minimum_required(VERSION 3.28)

project(CppTest
    VERSION 0.1.0
    DESCRIPTION "Programs To Test Functionality"
    LANGUAGES CXX)

message("Compiler is: ${CMAKE_CXX_COMPILER_ID}")

include(CMakeInterfaces/CMakeInterfaces.cmake)

add_subdirectory(HelloWorld)
add_subdirectory(Modules)

add_executable(Driver)
target_sources(Driver PRIVATE Driver.cpp)
target_compile_features(Driver PRIVATE cxx_std_20)
target_link_libraries(Driver PRIVATE
    EQX-DebugSymbols EQX-Optimizations EQX-Sanitizers EQX-Warnings)

set_target_properties(Driver PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

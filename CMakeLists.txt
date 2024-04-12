cmake_minimum_required(VERSION 3.28)

project(CppTest
    VERSION 0.1.0
    DESCRIPTION "Programs To Test Functionality"
    LANGUAGES CXX)

message("Compiler is: ${CMAKE_CXX_COMPILER_ID}")

add_subdirectory(CMakeInterfaces)

add_subdirectory(HelloWorld)

add_executable(Driver)
target_sources(Driver PRIVATE Driver.cpp)
target_link_libraries(Driver PRIVATE
    DebugSymbols Optimizations Sanitizers WarningFlags)

set_target_properties(Driver PROPERTIES
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

cmake_minimum_required(VERSION 3.28)

project(CppTest
    VERSION 1.0.0
    DESCRIPTION "Programs To Test Functionality"
    LANGUAGES CXX)

message("Compiler is: ${CMAKE_CXX_COMPILER_ID}")

include(EQX-CMakeInterfaces/Interfaces.cmake)

add_subdirectory(ASan)
add_subdirectory(Format)
add_subdirectory(HelloWorld)
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
else ()
    add_subdirectory(LSan)
endif()
add_subdirectory(Modules)
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
else ()
    add_subdirectory(UBSan)
endif()

add_executable(Driver)
target_sources(Driver PRIVATE Driver.cpp)
target_compile_features(Driver PRIVATE cxx_std_20)

target_link_libraries(Driver PRIVATE EQX-Typical)

set_target_properties(Driver PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

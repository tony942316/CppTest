cmake_minimum_required(VERSION 3.28)

add_executable(Format)
target_sources(Format PRIVATE Main.cpp)
target_compile_features(Format PRIVATE cxx_std_20)

target_link_libraries(Format PRIVATE EQX-Warnings)
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_link_libraries(Format PRIVATE
        "$<$<CONFIG:Debug>:EQX-DebugSymbols;EQX-Sanitizers>"
        "$<$<CONFIG:Release>:EQX-Optimizations>")
else ()
    target_link_libraries(Format PRIVATE
        EQX-DebugSymbols EQX-Sanitizers)
endif()

set_target_properties(Format PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

cmake_minimum_required(VERSION 3.28)

add_executable(ASan)
target_sources(ASan PRIVATE Main.cpp)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_link_libraries(ASan PRIVATE
        "$<$<CONFIG:Debug>:EQX-DebugSymbols;EQX-Sanitizers>"
        "$<$<CONFIG:Release>:EQX-Optimizations>")
else ()
    target_link_libraries(ASan PRIVATE
        EQX-DebugSymbols EQX-ASan)
    target_compile_options(ASan PRIVATE -Wno-array-bounds)
endif()

set_target_properties(ASan PROPERTIES
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

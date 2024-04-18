cmake_minimum_required(VERSION 3.28)

add_executable(HelloWorld)
target_sources(HelloWorld PRIVATE Main.cpp)

target_link_libraries(HelloWorld PRIVATE EQX-Warnings)
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_link_libraries(HelloWorld PRIVATE
        "$<$<CONFIG:Debug>:EQX-DebugSymbols;EQX-Sanitizers>"
        "$<$<CONFIG:Release>:EQX-Optimizations>")
else ()
    target_link_libraries(HelloWorld PRIVATE
        EQX-DebugSymbols EQX-Sanitizers)
endif()

set_target_properties(HelloWorld PROPERTIES
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

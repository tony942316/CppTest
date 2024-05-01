cmake_minimum_required(VERSION 3.28)

add_executable(UBSan)
target_sources(UBSan PRIVATE Main.cpp)
target_link_libraries(UBSan PRIVATE
    EQX-DebugSymbols EQX-UBSan)

set_target_properties(UBSan PROPERTIES
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

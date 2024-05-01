cmake_minimum_required(VERSION 3.28)

add_executable(LSan)
target_sources(LSan PRIVATE Main.cpp)
target_link_libraries(LSan PRIVATE
    EQX-DebugSymbols EQX-LSan)

set_target_properties(LSan PROPERTIES
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

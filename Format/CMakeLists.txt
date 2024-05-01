cmake_minimum_required(VERSION 3.28)

add_executable(Format)
target_sources(Format PRIVATE Main.cpp)
target_compile_features(Format PRIVATE cxx_std_20)

target_link_libraries(Format PRIVATE EQX-Typical)

set_target_properties(Format PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

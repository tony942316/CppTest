cmake_minimum_required(VERSION 3.28)

add_executable(HelloWorld)
target_sources(HelloWorld PRIVATE Main.cpp)

set_target_properties(HelloWorld PROPERTIES
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

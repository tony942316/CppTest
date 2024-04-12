cmake_minimum_required(VERSION 3.28)

add_library(Foo STATIC)
target_sources(Foo
    PUBLIC FILE_SET CXX_MODULES FILES
        Foo.cpp)
target_compile_features(Foo PUBLIC cxx_std_20)

set_target_properties(Foo PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

add_executable(Modules)
target_sources(Modules PRIVATE Main.cpp)
target_link_libraries(Modules PRIVATE Foo)

set_target_properties(Modules PROPERTIES
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

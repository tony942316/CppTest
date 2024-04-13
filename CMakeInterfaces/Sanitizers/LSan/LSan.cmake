cmake_minimum_required(VERSION 3.28)

add_library(LSan INTERFACE)
target_compile_options(LSan INTERFACE -fsanitize=leak)
target_link_options(LSan INTERFACE -fsanitize=leak)

cmake_minimum_required(VERSION 3.28)

add_library(ASan INTERFACE)
target_compile_options(ASan INTERFACE -fsanitize=address)
target_link_options(ASan INTERFACE -fsanitize=address)

cmake_minimum_required(VERSION 3.28)

add_library(TSan INTERFACE)
target_compile_options(TSan INTERFACE -fsanitize=thread)
target_link_options(TSan INTERFACE -fsanitize=thread)

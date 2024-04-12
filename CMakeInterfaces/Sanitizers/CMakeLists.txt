cmake_minimum_required(VERSION 3.28)

add_subdirectory(ASan)
add_subdirectory(LSan)
add_subdirectory(TSan)
add_subdirectory(UBSan)

add_library(Sanitizers INTERFACE)
target_link_libraries(Sanitizers INTERFACE ASan LSan UBSan)

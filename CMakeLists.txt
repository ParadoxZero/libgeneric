cmake_minimum_required(VERSION 3.6)
project(data_structure)

set(CMAKE_C_STANDARD 99)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCE_FILES src/data_structure/library.c)
add_library(st_datastructures ${SOURCE_FILES})

cmake_minimum_required(VERSION 3.31)
project(BinarySearchTree C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(SOURCE_FILES main.c)
add_executable(BinarySearchTree_run ${SOURCE_FILES})

include_directories(BinarySearchTree_lib)
add_subdirectory(src)

target_link_libraries(BinarySearchTree_run BinarySearchTree_lib)

#add_subdirectory(tests)
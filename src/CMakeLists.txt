project(BinarySearchTree_lib)

set(HEADER_FILES binary-search-tree.h)
set(SOURCE_FILES binary-search-tree.c)

add_library(BinarySearchTree_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
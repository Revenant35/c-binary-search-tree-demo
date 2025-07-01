add_library(binary_search_tree STATIC
        binary-search-tree.c
)

target_include_directories(binary_search_tree PUBLIC
        "${PROJECT_SOURCE_DIR}/include"
)

add_executable(c_binary_search_tree_demo main.c)

target_link_libraries(c_binary_search_tree_demo PRIVATE binary_search_tree)
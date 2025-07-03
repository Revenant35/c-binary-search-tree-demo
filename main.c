#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arm/limits.h>

#include "src/binary-search-tree.h"

#define MAX_INPUT_LENGTH 16

int main(void) {
    BinarySearchTree *tree = create_binary_search_tree();
    char line[128];

    if (tree == nullptr) {
        return 1;
    }

    while (fgets(line, sizeof(line), stdin)) {
        if (strlen(line) <= 1) break;

        char command[16];
        int x;
        if (sscanf(line, "%s %d", command, &x) == 2) {
            if (strcmp(command, "insert") == 0) {
                insert_binary_search_tree(tree, x);
                printf("Inserted %d\n", x);
            } else if (strcmp(command, "remove") == 0) {
                delete_binary_search_tree(tree, x);
                printf("Removed %d\n", x);
            } else if (strcmp(command, "find") == 0) {
                const bool found = search_binary_search_tree(tree, x);
                printf(found ? "Found %d\n" : "Not found\n", x);
            } else if (strcmp(command, "floor") == 0) {
                floor_binary_search_tree(tree, x);
            } else if (strcmp(command, "ceil") == 0) {
                ceil_binary_search_tree(tree, x);
            } else {
                printf("Unknown command\n");
            }
        } else if (sscanf(line, "%s", command) == 1) {
            if (strcmp(command, "min") == 0) {
                const int min = minimum_value_binary_search_tree(tree);
                if (min == INT_MAX) {
                    printf("Tree is empty\n");
                } else {
                    printf("Min: %d\n", min);
                }
            } else if (strcmp(command, "max") == 0) {
                const int max = maximum_value_binary_search_tree(tree);
                if (max == INT_MIN) {
                    printf("Tree is empty\n");
                } else {
                    printf("Max: %d\n", max);
                }
            } else if (strcmp(command, "exit") == 0) {
                break;
            } else {
                printf("Unknown command\n");
            }
        }
    }

    destroy_binary_search_tree(tree);
    return 0;
}
#include <stdlib.h>

#include "binary-search-tree.h"

BinarySearchTree* create_binary_search_tree() {
    BinarySearchTree* tree = malloc(sizeof(BinarySearchTree));
    if (tree != NULL) {
        tree->root = nullptr;
    }
    return tree;
}

void destroy_binary_search_tree(BinarySearchTree* tree) {
    if (tree != nullptr) {
        free(tree);
        tree = nullptr;
    }
}

void insert_binary_search_tree(BinarySearchTree* tree, int data) {
}

bool search_binary_search_tree(const BinarySearchTree* tree, int data) {
    return false;
}

bool delete_binary_search_tree(BinarySearchTree* tree, int data) {
    return false;
}

void print_in_order_binary_search_tree(const BinarySearchTree* tree, void (*print)(int data)) {

}

void print_pre_order_binary_search_tree(const BinarySearchTree* tree, void (*print)(int data)) {

}

void print_post_order_binary_search_tree(const BinarySearchTree* tree, void (*print)(int data)) {

}
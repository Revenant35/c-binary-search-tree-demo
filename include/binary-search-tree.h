#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* root;
} BinarySearchTree;

BinarySearchTree* create_binary_search_tree();
void destroy_binary_search_tree(BinarySearchTree* tree);

void insert_binary_search_tree(BinarySearchTree* tree, int data);
bool search_binary_search_tree(const BinarySearchTree* tree, int data);
bool delete_binary_search_tree(BinarySearchTree* tree, int data);

void print_in_order_binary_search_tree(const BinarySearchTree* tree, void (*print)(int data));
void print_pre_order_binary_search_tree(const BinarySearchTree* tree, void (*print)(int data));
void print_post_order_binary_search_tree(const BinarySearchTree* tree, void (*print)(int data));

#endif //BINARY_SEARCH_TREE_H

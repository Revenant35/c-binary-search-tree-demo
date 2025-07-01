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

void print_inorder_binary_search_tree(const BinarySearchTree* tree);
void print_preorder_binary_search_tree(const BinarySearchTree* tree);
void print_postorder_binary_search_tree(const BinarySearchTree* tree);

#endif //BINARY_SEARCH_TREE_H

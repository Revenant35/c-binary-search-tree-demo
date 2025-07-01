#include <stdlib.h>

#include "binary-search-tree.h"

#include <assert.h>
#include <stdio.h>

static Node *create_node(const int data) {
    Node *node = malloc(sizeof(Node));
    if (node != nullptr) {
        node->data = data;
    }
    return node;
}

static void preorder_traversal(Node *node, void (*fn)(Node *)) {
    if (node == nullptr) return;
    fn(node);
    preorder_traversal(node->left, fn);
    preorder_traversal(node->right, fn);
}

static void inorder_traversal(Node *node, void (*fn)(Node *)) {
    if (node == nullptr) return;
    inorder_traversal(node->left, fn);
    fn(node);
    inorder_traversal(node->right, fn);
}

static void postorder_traversal(Node *node, void (*fn)(Node *)) {
    if (node == nullptr) return;
    postorder_traversal(node->left, fn);
    postorder_traversal(node->right, fn);
    fn(node);
}

static void free_node(Node *node) {
    free(node);
}

static void print_node(Node *node) {
    printf("%d ", node->data);
}

static void insert_binary_search_tree_node(Node* node, const int data) {
    assert(node != nullptr);

    if (data > node->data) {
        if (node->right == nullptr) node->right = create_node(data);
        else return insert_binary_search_tree_node(node->right, data);
    } else {
        if (node->left == nullptr) node->left = create_node(data);
        else return insert_binary_search_tree_node(node->left, data);
    }
}

static bool search_binary_search_tree_node(const Node* node, const int data) {
    if (node == nullptr) return false;
    if (node->data == data) return true;

    if (data > node->data) {
        return search_binary_search_tree_node(node->right, data);
    } else {
        return search_binary_search_tree_node(node->left, data);
    }
}

BinarySearchTree* create_binary_search_tree() {
    BinarySearchTree* tree = malloc(sizeof(BinarySearchTree));
    if (tree != NULL) {
        tree->root = nullptr;
    }
    return tree;
}

void destroy_binary_search_tree(BinarySearchTree* tree) {
    if (tree == nullptr) return;

    if (tree->root != nullptr) postorder_traversal(tree->root, free_node);

    free(tree);
}

void insert_binary_search_tree(BinarySearchTree* tree, const int data) {
    if (tree == nullptr) return;

    if (tree->root == nullptr) {
        tree->root = create_node(data);
        return;
    }

    return insert_binary_search_tree_node(tree->root, data);
}

bool search_binary_search_tree(const BinarySearchTree* tree, const int data) {
    if (tree == nullptr || tree->root == nullptr) return false;

    return search_binary_search_tree_node(tree->root, data);
}

bool delete_binary_search_tree(BinarySearchTree* tree, int data) {
    return false;
}

void print_inorder_binary_search_tree(const BinarySearchTree* tree) {
    if (tree == nullptr) return;
    inorder_traversal(tree->root, print_node);
}

void print_preorder_binary_search_tree(const BinarySearchTree* tree) {
    if (tree == nullptr) return;
    preorder_traversal(tree->root, print_node);
}

void print_postorder_binary_search_tree(const BinarySearchTree* tree) {
    if (tree == nullptr) return;
    postorder_traversal(tree->root, print_node);
}
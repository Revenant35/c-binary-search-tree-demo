#include <stdlib.h>

#include "binary-search-tree.h"

#include <assert.h>
#include <stdio.h>
#include <arm/limits.h>

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

static Node *find_minimum_value_node(Node *node) {
    if (node == nullptr) return nullptr;

    Node *current = node;
    while (current->left != nullptr) current = current->left;

    return current;
}

static Node *find_maximum_value_node(Node *node) {
    if (node == nullptr) return nullptr;

    Node *current = node;
    while (current->right != nullptr) current = current->right;

    return current;
}

static bool is_leaf_node(const Node *node) {
    assert(node != nullptr);

    return node->left == nullptr && node->right == nullptr;
}

static bool has_two_children(const Node *node) {
    assert(node != nullptr);

    return node->left != nullptr && node->right != nullptr;
}

static bool insert_binary_search_tree_node(Node *node, const int data) {
    assert(node != nullptr);

    if (data > node->data) {
        if (node->right != nullptr) {
            return insert_binary_search_tree_node(node->right, data);
        }

        node->right = create_node(data);
        return true;
    }

    if (data < node->data) {
        if (node->left != nullptr) {
            return insert_binary_search_tree_node(node->left, data);
        }

        node->left = create_node(data);
        return true;
    }

    return false;
}

static bool search_binary_search_tree_node(const Node *node, const int data) {
    if (node == nullptr) return false;
    if (node->data == data) return true;

    if (data > node->data) {
        return search_binary_search_tree_node(node->right, data);
    } else {
        return search_binary_search_tree_node(node->left, data);
    }
}

static bool delete_binary_search_tree_node(Node **node, const int data) {
    if (*node == nullptr) return false;

    if (data < (*node)->data) {
        return delete_binary_search_tree_node(&(*node)->left, data);
    }

    if (data > (*node)->data) {
        return delete_binary_search_tree_node(&(*node)->right, data);
    }

    // Node to delete found
    Node *target = *node;

    if (is_leaf_node(target)) {
        free(target);
        *node = nullptr;
        return true;
    }

    if (has_two_children(target)) {
        const Node *successor = find_minimum_value_node(target->right);
        target->data = successor->data;
        return delete_binary_search_tree_node(&target->right, successor->data);
    }

    // Case 3: One child
    Node *child = target->left != nullptr ? target->left : target->right;
    free(target);
    *node = child;
    return true;
}

BinarySearchTree *create_binary_search_tree() {
    BinarySearchTree *tree = malloc(sizeof(BinarySearchTree));
    if (tree != NULL) {
        tree->root = nullptr;
    }
    return tree;
}

void destroy_binary_search_tree(BinarySearchTree *tree) {
    if (tree == nullptr) return;

    if (tree->root != nullptr) postorder_traversal(tree->root, free_node);

    free(tree);
}

bool insert_binary_search_tree(BinarySearchTree *tree, const int data) {
    if (tree == nullptr) return false;

    if (tree->root == nullptr) {
        tree->root = create_node(data);
        return true;
    }

    return insert_binary_search_tree_node(tree->root, data);
}

bool search_binary_search_tree(const BinarySearchTree *tree, const int data) {
    if (tree == nullptr || tree->root == nullptr) return false;

    return search_binary_search_tree_node(tree->root, data);
}

bool delete_binary_search_tree(BinarySearchTree *tree, const int data) {
    if (tree == NULL) return false;
    return delete_binary_search_tree_node(&tree->root, data);
}

void print_inorder_binary_search_tree(const BinarySearchTree *tree) {
    if (tree == nullptr) return;
    inorder_traversal(tree->root, print_node);
}

void print_preorder_binary_search_tree(const BinarySearchTree *tree) {
    if (tree == nullptr) return;
    preorder_traversal(tree->root, print_node);
}

void print_postorder_binary_search_tree(const BinarySearchTree *tree) {
    if (tree == nullptr) return;
    postorder_traversal(tree->root, print_node);
}

int maximum_value_binary_search_tree(const BinarySearchTree* tree) {
    if (tree == nullptr || tree->root == nullptr) return INT_MIN;
    const Node *maximum = find_maximum_value_node(tree->root);
    return maximum->data;
}

int minimum_value_binary_search_tree(const BinarySearchTree* tree) {
    if (tree == nullptr || tree->root == nullptr) return INT_MAX;
    const Node *minimum = find_minimum_value_node(tree->root);
    return minimum->data;
}

int floor_binary_search_tree(const BinarySearchTree* tree, int data) {
    if (tree == nullptr || tree->root == nullptr) return INT_MIN;
    // TODO: Implementation
}

int ceil_binary_search_tree(const BinarySearchTree* tree, int data) {
    if (tree == nullptr || tree->root == nullptr) return INT_MAX;
    // TODO: Implementation
}

#include <check.h>
#include <stdlib.h>
#include "../src/binary-search-tree.h"

START_TEST(create_binary_search_tree_should_create_binary_search_tree)
{
    // Arrange & Act
    BinarySearchTree *tree = create_binary_search_tree();

    // Assert
    ck_assert_ptr_nonnull(tree);
    ck_assert_ptr_null(tree->root);

    // Cleanup
    destroy_binary_search_tree(tree);
}
END_TEST

START_TEST(destroy_binary_search_tree_should_free_binary_search_tree)
{
    // Arrange
    BinarySearchTree *tree = create_binary_search_tree();

    // Act
    destroy_binary_search_tree(tree);

    // Assert
    ck_assert_ptr_nonnull(tree);
    ck_assert_ptr_null(tree->root);
}
END_TEST

START_TEST(destroy_binary_search_tree_should_free_all_tree_nodes)
{
    // Arrange
    BinarySearchTree *tree = create_binary_search_tree();
    insert_binary_search_tree(tree, 3);
    insert_binary_search_tree(tree, 4);
    insert_binary_search_tree(tree, 1);
    insert_binary_search_tree(tree, 0);
    insert_binary_search_tree(tree, 2);
    ck_assert_ptr_nonnull(tree->root);
    ck_assert_ptr_nonnull(tree->root->left);
    ck_assert_ptr_nonnull(tree->root->right);
    ck_assert_ptr_nonnull(tree->root->left->left);
    ck_assert_ptr_nonnull(tree->root->left->right);
    /*
    *    3
    *   / \
    *  1   4
    * / \
    * 0 2
    */
    const Node *node_three = tree->root;
    const Node *node_one = tree->root->left;
    const Node *node_four = tree->root->right;
    const Node *node_zero = tree->root->left->left;
    const Node *node_two = tree->root->left->right;

    // Act
    destroy_binary_search_tree(tree);

    // Assert
    ck_assert_ptr_null(node_three);
    ck_assert_ptr_null(node_one);
    ck_assert_ptr_null(node_four);
    ck_assert_ptr_null(node_zero);
    ck_assert_ptr_null(node_two);
}
END_TEST

Suite *test_binary_search_tree_suite(void)
{
    Suite *s = suite_create("BinarySearchTree");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, create_binary_search_tree_should_create_binary_search_tree);
    tcase_add_test(tc_core, destroy_binary_search_tree_should_free_binary_search_tree);
    tcase_add_test(tc_core, destroy_binary_search_tree_should_free_all_tree_nodes);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    Suite *s = test_binary_search_tree_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    const int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

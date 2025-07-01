#include <check.h>
#include <stdlib.h>
#include <arm/limits.h>

#include "../src/binary-search-tree.h"

START_TEST(create_binary_search_tree_should_create_binary_search_tree) {
    // Arrange & Act
    BinarySearchTree *tree = create_binary_search_tree();

    // Assert
    ck_assert_ptr_nonnull(tree);
    ck_assert_ptr_null(tree->root);

    // Cleanup
    destroy_binary_search_tree(tree);
}

END_TEST

START_TEST(insert_binary_search_tree_should_return_false_when_tree_is_null) {
    // Arrange
    BinarySearchTree *tree = nullptr;

    // Act
    const bool result = insert_binary_search_tree(tree, 3);

    // Assert
    ck_assert(!result);
}

END_TEST

START_TEST(insert_binary_search_tree_should_return_true_and_insert_data_when_tree_is_empty) {
    // Arrange
    BinarySearchTree *tree = create_binary_search_tree();
    constexpr int data = 5;

    // Act
    const bool result = insert_binary_search_tree(tree, data);

    // Assert
    const bool found = search_binary_search_tree(tree, data);
    ck_assert(result);
    ck_assert(found);
}

END_TEST

START_TEST(insert_binary_search_tree_should_return_true_and_insert_data_when_entry_not_already_in_tree) {
    // Arrange
    BinarySearchTree *tree = create_binary_search_tree();
    insert_binary_search_tree(tree, 1);
    insert_binary_search_tree(tree, 2);
    constexpr int data = 5;

    // Act
    const bool result = insert_binary_search_tree(tree, data);

    // Assert
    const bool found = search_binary_search_tree(tree, data);
    ck_assert(result);
    ck_assert(found);
}

END_TEST

START_TEST(insert_binary_search_tree_should_return_false_when_entry_already_in_tree) {
    // Arrange
    BinarySearchTree *tree = create_binary_search_tree();
    constexpr int data = 5;
    insert_binary_search_tree(tree, data);

    // Act
    const bool result = insert_binary_search_tree(tree, data);

    // Assert
    ck_assert(!result);
}

END_TEST

START_TEST(search_binary_search_tree_should_return_false_when_tree_is_null) {
    // Arrange & Act
    const bool result = search_binary_search_tree(nullptr, 4);

    // Assert
    ck_assert(!result);
}

END_TEST

START_TEST(search_binary_search_tree_should_return_false_when_tree_is_empty) {
    // Arrange
    const BinarySearchTree *tree = create_binary_search_tree();

    // Act
    const bool result = search_binary_search_tree(tree, 4);

    // Assert
    ck_assert(!result);
}

END_TEST

START_TEST(search_binary_search_tree_should_return_false_when_entry_not_in_tree) {
    // Arrange
    BinarySearchTree *tree = create_binary_search_tree();
    insert_binary_search_tree(tree, 1);
    insert_binary_search_tree(tree, 2);
    insert_binary_search_tree(tree, 3);

    // Act
    const bool result = search_binary_search_tree(tree, 4);

    // Assert
    ck_assert(!result);
}

END_TEST

START_TEST(search_binary_search_tree_should_return_true_when_entry_found_at_root) {
    // Arrange
    BinarySearchTree *tree = create_binary_search_tree();
    constexpr int data = 5;
    insert_binary_search_tree(tree, data);

    // Act
    const bool result = search_binary_search_tree(tree, data);

    // Assert
    ck_assert(result);
}

END_TEST

START_TEST(search_binary_search_tree_should_return_true_when_entry_found_in_children) {
    // Arrange
    BinarySearchTree *tree = create_binary_search_tree();
    insert_binary_search_tree(tree, 1);
    insert_binary_search_tree(tree, 2);
    insert_binary_search_tree(tree, 3);
    insert_binary_search_tree(tree, 4);
    constexpr int data = 5;
    insert_binary_search_tree(tree, data);

    // Act
    const bool result = search_binary_search_tree(tree, data);

    // Assert
    ck_assert(result);
}

END_TEST

START_TEST(delete_binary_search_tree_should_return_false_when_tree_is_null) {
    // Arrange & Act
    const bool result = delete_binary_search_tree(nullptr, 4);

    // Assert
    ck_assert(!result);
}

END_TEST

START_TEST(delete_binary_search_tree_should_return_false_when_tree_is_empty) {
    // Arrange
    BinarySearchTree *tree = create_binary_search_tree();

    // Act
    const bool result = delete_binary_search_tree(tree, 4);

    // Assert
    ck_assert(!result);
}

END_TEST

START_TEST(delete_binary_search_tree_should_return_false_when_entry_not_in_tree) {
    // Arrange
    BinarySearchTree *tree = create_binary_search_tree();
    insert_binary_search_tree(tree, 1);
    insert_binary_search_tree(tree, 2);
    insert_binary_search_tree(tree, 3);
    insert_binary_search_tree(tree, 4);

    // Act
    const bool result = delete_binary_search_tree(tree, 5);

    // Assert
    ck_assert(!result);
}

END_TEST

START_TEST(delete_binary_search_tree_should_return_true_and_remove_entry_when_entry_is_root_node) {
    // Arrange
    BinarySearchTree *tree = create_binary_search_tree();
    insert_binary_search_tree(tree, 1);

    // Act
    const bool result = delete_binary_search_tree(tree, 1);

    // Assert
    ck_assert(result);
    ck_assert(!search_binary_search_tree(tree, 1));
}

END_TEST

START_TEST(delete_binary_search_tree_should_return_true_and_remove_entry_when_entry_is_leaf_node) {
    // Arrange
    BinarySearchTree *tree = create_binary_search_tree();
    insert_binary_search_tree(tree, 1);
    insert_binary_search_tree(tree, 2);

    // Act
    const bool result = delete_binary_search_tree(tree, 2);

    // Assert
    ck_assert(result);
    ck_assert(search_binary_search_tree(tree, 1));
    ck_assert(!search_binary_search_tree(tree, 2));
}

END_TEST

START_TEST(delete_binary_search_tree_should_return_true_and_remove_entry_when_entry_has_one_child) {
    // Arrange
    BinarySearchTree *tree = create_binary_search_tree();
    insert_binary_search_tree(tree, 1);
    insert_binary_search_tree(tree, 2);
    insert_binary_search_tree(tree, 3);

    // Act
    const bool result = delete_binary_search_tree(tree, 1);

    // Assert
    ck_assert(result);
    ck_assert(tree->root->data == 2);
    ck_assert(tree->root->right->data == 3);
    ck_assert(!search_binary_search_tree(tree, 1));
    ck_assert(search_binary_search_tree(tree, 2));
    ck_assert(search_binary_search_tree(tree, 3));
}

END_TEST

START_TEST(delete_binary_search_tree_should_return_true_and_remove_entry_when_entry_has_two_children) {
    /*
     *       6
     *      / \
     *     4   8
     *    /   / \
     *   2   7   9
     *  / \
     * 0   3
     */

    // Arrange
    BinarySearchTree *tree = create_binary_search_tree();
    insert_binary_search_tree(tree, 6);
    insert_binary_search_tree(tree, 4);
    insert_binary_search_tree(tree, 8);
    insert_binary_search_tree(tree, 2);
    insert_binary_search_tree(tree, 7);
    insert_binary_search_tree(tree, 9);
    insert_binary_search_tree(tree, 0);
    insert_binary_search_tree(tree, 3);

    // Act
    const bool result = delete_binary_search_tree(tree, 6);

    // Assert
    ck_assert(result);
    ck_assert(tree->root->data == 7);
    ck_assert(tree->root->right->data == 8);
    ck_assert(tree->root->right->left == nullptr);
    ck_assert(!search_binary_search_tree(tree, 6));
}

END_TEST

START_TEST(maximum_value_binary_search_tree_should_return_min_when_tree_is_null) {
    // Arrange
    const BinarySearchTree *tree = nullptr;
    constexpr int expected = INT_MIN;

    // Act
    const int value = maximum_value_binary_search_tree(tree);

    // Assert
    ck_assert_int_eq(value, expected);
}

START_TEST(maximum_value_binary_search_tree_should_return_min_when_tree_is_empty) {
    // Arrange
    const BinarySearchTree *tree = create_binary_search_tree();
    constexpr int expected = INT_MIN;

    // Act
    const int value = maximum_value_binary_search_tree(tree);

    // Assert
    ck_assert_int_eq(value, expected);
}

START_TEST(maximum_value_binary_search_tree_should_return_maximum_value_when_tree_has_entries) {
    // Arrange
    BinarySearchTree *tree = create_binary_search_tree();
    insert_binary_search_tree(tree, 1);
    insert_binary_search_tree(tree, 2);
    insert_binary_search_tree(tree, 3);

    // Act
    const int value = maximum_value_binary_search_tree(tree);

    // Assert
    ck_assert_int_eq(value, 3);
}

START_TEST(minimum_value_binary_search_tree_should_return_max_when_tree_is_null) {
    // Arrange
    const BinarySearchTree *tree = nullptr;
    constexpr int expected = INT_MAX;

    // Act
    const int value = minimum_value_binary_search_tree(tree);

    // Assert
    ck_assert_int_eq(value, expected);
}

START_TEST(minimum_value_binary_search_tree_should_return_max_when_tree_is_empty) {
    // Arrange
    const BinarySearchTree *tree = create_binary_search_tree();
    constexpr int expected = INT_MAX;

    // Act
    const int value = minimum_value_binary_search_tree(tree);

    // Assert
    ck_assert_int_eq(value, expected);
}

START_TEST(minimum_value_binary_search_tree_should_return_minimum_value_when_tree_has_entries) {
    // Arrange
    BinarySearchTree *tree = create_binary_search_tree();
    insert_binary_search_tree(tree, 0);
    insert_binary_search_tree(tree, -1);
    insert_binary_search_tree(tree, -2);
    insert_binary_search_tree(tree, 6);

    // Act
    const int value = minimum_value_binary_search_tree(tree);

    // Assert
    ck_assert_int_eq(value, -2);
}

END_TEST

Suite *test_binary_search_tree_suite(void) {
    Suite *s = suite_create("BinarySearchTree");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, create_binary_search_tree_should_create_binary_search_tree);
    tcase_add_test(tc_core, insert_binary_search_tree_should_return_false_when_tree_is_null);
    tcase_add_test(tc_core, insert_binary_search_tree_should_return_true_and_insert_data_when_tree_is_empty);
    tcase_add_test(
        tc_core, insert_binary_search_tree_should_return_true_and_insert_data_when_entry_not_already_in_tree);
    tcase_add_test(tc_core, insert_binary_search_tree_should_return_false_when_entry_already_in_tree);
    tcase_add_test(tc_core, search_binary_search_tree_should_return_false_when_tree_is_null);
    tcase_add_test(tc_core, search_binary_search_tree_should_return_false_when_tree_is_empty);
    tcase_add_test(tc_core, search_binary_search_tree_should_return_false_when_entry_not_in_tree);
    tcase_add_test(tc_core, search_binary_search_tree_should_return_true_when_entry_found_at_root);
    tcase_add_test(tc_core, search_binary_search_tree_should_return_true_when_entry_found_in_children);
    tcase_add_test(tc_core, delete_binary_search_tree_should_return_false_when_tree_is_null);
    tcase_add_test(tc_core, delete_binary_search_tree_should_return_false_when_tree_is_empty);
    tcase_add_test(tc_core, delete_binary_search_tree_should_return_false_when_entry_not_in_tree);
    tcase_add_test(tc_core, delete_binary_search_tree_should_return_true_and_remove_entry_when_entry_is_root_node);
    tcase_add_test(tc_core, delete_binary_search_tree_should_return_true_and_remove_entry_when_entry_is_leaf_node);
    tcase_add_test(tc_core, delete_binary_search_tree_should_return_true_and_remove_entry_when_entry_has_one_child);
    tcase_add_test(tc_core, delete_binary_search_tree_should_return_true_and_remove_entry_when_entry_has_two_children);
    tcase_add_test(tc_core, maximum_value_binary_search_tree_should_return_min_when_tree_is_null);
    tcase_add_test(tc_core, maximum_value_binary_search_tree_should_return_min_when_tree_is_empty);
    tcase_add_test(tc_core, maximum_value_binary_search_tree_should_return_maximum_value_when_tree_has_entries);
    tcase_add_test(tc_core, minimum_value_binary_search_tree_should_return_max_when_tree_is_null);
    tcase_add_test(tc_core, minimum_value_binary_search_tree_should_return_max_when_tree_is_empty);
    tcase_add_test(tc_core, minimum_value_binary_search_tree_should_return_minimum_value_when_tree_has_entries);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    Suite *s = test_binary_search_tree_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    const int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

#include "btree.h"
#include <cgreen/cgreen.h>
#include <string.h>

Describe(BinaryTree);
BeforeEach(BinaryTree) {}
AfterEach(BinaryTree) {}

Ensure(BinaryTree, when_the_tree_is_NULL) {
  BTree *tree = btree_insert(NULL, 10);

  assert_that(tree, is_not_equal_to(NULL));
  assert_that(tree->data, is_equal_to(10));
}

Ensure(BinaryTree, when_inserting_an_item_less_than_the_root_in_a_tree_it_creates_a_node_on_the_left_side) {
  BTree *tree = btree_init(10);
  btree_insert(tree, -5);

  assert_that(tree->left, is_not_equal_to(NULL));
  assert_that(tree->left->data, is_equal_to(-5));
}

Ensure(BinaryTree, when_inserting_an_item_greater_than_the_root_in_a_tree_it_creates_a_node_on_the_right_side) {
  BTree *tree = btree_init(10);

  btree_insert(tree, 16);

  assert_that(tree->right, is_not_equal_to(NULL));
  assert_that(tree->right->data, is_equal_to(16));
}

Ensure(BinaryTree, when_inserting_an_item_equal_to_the_root_in_a_tree_it_creates_a_node_on_the_left_side) {
  BTree *tree = btree_init(10);

  btree_insert(tree, 10);

  assert_that(tree->left, is_not_equal_to(NULL));
  assert_that(tree->left->data, is_equal_to(10));
}

Ensure(BinaryTree, when_inserting_multiple_items_into_a_tree_it_inserts_in_the_correct_position) {
  BTree *tree = btree_insert(NULL, 10);

  btree_insert(tree, -5);
  btree_insert(tree, 16);

  assert_that(tree->data, is_equal_to(10));
  assert_that(tree->left->data, is_equal_to(-5));
  assert_that(tree->right->data, is_equal_to(16));

  btree_insert(tree, -8);

  assert_that(tree->left->left, is_not_equal_to(NULL));
  assert_that(tree->left->left->data, is_equal_to(-8));

  btree_insert(tree, 7);

  assert_that(tree->left->right, is_not_equal_to(NULL));
  assert_that(tree->left->right->data, is_equal_to(7));

  btree_insert(tree, 18);

  assert_that(tree->right->right, is_not_equal_to(NULL));
  assert_that(tree->right->right->data, is_equal_to(18));

  btree_insert(tree, 6);

  assert_that(tree->left->right->left, is_not_equal_to(NULL));
  assert_that(tree->left->right->left->data, is_equal_to(6));
}

TestSuite *binary_search_tree_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, BinaryTree, when_the_tree_is_NULL);
  add_test_with_context(suite, BinaryTree, when_inserting_an_item_less_than_the_root_in_a_tree_it_creates_a_node_on_the_left_side);
  add_test_with_context(suite, BinaryTree, when_inserting_an_item_greater_than_the_root_in_a_tree_it_creates_a_node_on_the_right_side);
  add_test_with_context(suite, BinaryTree, when_inserting_an_item_equal_to_the_root_in_a_tree_it_creates_a_node_on_the_left_side);
  add_test_with_context(suite, BinaryTree, when_inserting_multiple_items_into_a_tree_it_inserts_in_the_correct_position);

  return suite;
}

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, binary_search_tree_tests());
  return run_test_suite(suite, create_text_reporter());
}

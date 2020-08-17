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

Ensure(
    BinaryTree,
    when_inserting_an_item_less_than_the_root_in_a_tree_it_creates_a_node_on_the_left_side) {
  BTree *tree = btree_insert(NULL, 10);
  btree_insert(tree, -5);

  assert_that(tree->left, is_not_equal_to(NULL));
  assert_that(tree->left->data, is_equal_to(-5));
}

Ensure(
    BinaryTree,
    when_inserting_an_item_greater_than_the_root_in_a_tree_it_creates_a_node_on_the_right_side) {
  BTree *tree = btree_insert(NULL, 10);

  btree_insert(tree, 16);

  assert_that(tree->right, is_not_equal_to(NULL));
  assert_that(tree->right->data, is_equal_to(16));
}

Ensure(
    BinaryTree,
    when_inserting_an_item_equal_to_the_root_in_a_tree_it_creates_a_node_on_the_left_side) {
  BTree *tree = btree_insert(NULL, 10);

  btree_insert(tree, 10);

  assert_that(tree->left, is_not_equal_to(NULL));
  assert_that(tree->left->data, is_equal_to(10));
}

Ensure(
    BinaryTree,
    when_inserting_multiple_items_into_a_tree_it_inserts_in_the_correct_position) {
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

Ensure(BinaryTree, when_rebalancing_a_tree) {
  BTree *tree = btree_insert(NULL, 1);
  tree->right = btree_initialize(tree, 5);
  tree->right->left = btree_initialize(tree->right, 2);
  tree->right->left->right = btree_initialize(tree->right->left, 4);

  tree = btree_rebalance(tree->right->left->right);

  assert_that(tree, is_not_equal_to(NULL));
  assert_that(tree->data, is_equal_to(2));

  assert_that(tree->left->data, is_equal_to(1));
  assert_that(tree->right->data, is_equal_to(4));
  assert_that(tree->right->right->data, is_equal_to(5));
}

Ensure(
    BinaryTree,
    when_inserting_items_described_in_the_assignment_it_inserts_in_the_expected_position_in_the_tree) {
  BTree *tree = btree_insert(NULL, 1);
  tree = btree_insert(tree, 5);
  tree = btree_insert(tree, 2);
  tree = btree_insert(tree, 4);
  tree = btree_insert(tree, 3);

  assert_that(tree, is_not_equal_to(NULL));
  assert_that(tree->data, is_equal_to(2));
  assert_that(tree->left->data, is_equal_to(1));
  assert_that(tree->right->data, is_equal_to(4));
  assert_that(tree->right->right->data, is_equal_to(5));
}

Ensure(BinaryTree, when_calculating_the_size_of_the_tree)
{
  BTree *tree = btree_insert(NULL, 1);
  tree = btree_insert(tree, 5);
  tree = btree_insert(tree, 2);
  tree = btree_insert(tree, 4);
  tree = btree_insert(tree, 3);

  assert_that(btree_size(tree), is_equal_to(5));
}

TestSuite *binary_search_tree_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, BinaryTree, when_the_tree_is_NULL);
  add_test_with_context(
      suite, BinaryTree,
      when_inserting_an_item_less_than_the_root_in_a_tree_it_creates_a_node_on_the_left_side);
  add_test_with_context(
      suite, BinaryTree,
      when_inserting_an_item_greater_than_the_root_in_a_tree_it_creates_a_node_on_the_right_side);
  add_test_with_context(
      suite, BinaryTree,
      when_inserting_an_item_equal_to_the_root_in_a_tree_it_creates_a_node_on_the_left_side);
  add_test_with_context(
      suite, BinaryTree,
      when_inserting_multiple_items_into_a_tree_it_inserts_in_the_correct_position);
  add_test_with_context(suite, BinaryTree, when_rebalancing_a_tree);
  /*add_test_with_context(*/
      /*suite, BinaryTree,*/
      /*when_inserting_items_described_in_the_assignment_it_inserts_in_the_expected_position_in_the_tree);*/

  add_test_with_context(suite, BinaryTree, when_calculating_the_size_of_the_tree);
  return suite;
}

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, binary_search_tree_tests());
  return run_test_suite(suite, create_text_reporter());
}

#include "btree.h"
#include <cgreen/cgreen.h>
#include <string.h>

Describe(BinaryTree);
BeforeEach(BinaryTree) {}
AfterEach(BinaryTree) {}

Ensure(BinaryTree, when_a_tree_is_NULL) {
  assert_that(btree_is_bst(NULL), is_equal_to(true));
}

Ensure(BinaryTree, when_a_tree_has_a_single_node) {
  BTree *tree = btree_init(100);

  assert_that(btree_is_bst(tree), is_equal_to(true));
}

Ensure(BinaryTree, when_the_node_on_the_left_is_greater_than_the_root) {
  BTree *tree = btree_init(100);
  tree->left = btree_init(200);

  assert_that(btree_is_bst(tree), is_equal_to(false));
}

Ensure(BinaryTree, when_the_node_on_the_right_is_less_than_the_root) {
  BTree *tree = btree_init(200);
  tree->right = btree_init(100);

  assert_that(btree_is_bst(tree), is_equal_to(false));
}

Ensure(BinaryTree, when_a_node_on_the_left_subtree_is_less_than_an_ancestor) {
  BTree *tree = btree_init(300);
  tree->left = btree_init(100);
  tree->left->right = btree_init(400);

  assert_that(btree_is_bst(tree), is_equal_to(false));
}

Ensure(BinaryTree, when_a_node_on_the_right_subtree_is_greater_than_an_ancestor) {
  BTree *tree = btree_init(300);
  tree->right = btree_init(500);
  tree->right->left = btree_init(200);

  assert_that(btree_is_bst(tree), is_equal_to(false));
}

Ensure(BinaryTree, when_the_tree_is_a_binary_search_tree) {
  BTree *tree = btree_init(10);
  tree->left = btree_init(-5);
  tree->left->left = btree_init(-10);
  tree->left->right = btree_init(5);

  tree->right = btree_init(25);
  tree->right->left = btree_init(23);
  tree->right->right = btree_init(36);

  assert_that(btree_is_bst(tree), is_equal_to(true));
}

TestSuite *binary_search_tree_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, BinaryTree, when_a_tree_is_NULL);
  add_test_with_context(suite, BinaryTree, when_a_tree_has_a_single_node);
  add_test_with_context(suite, BinaryTree, when_the_node_on_the_left_is_greater_than_the_root);
  add_test_with_context(suite, BinaryTree, when_the_node_on_the_right_is_less_than_the_root);
  add_test_with_context(suite, BinaryTree, when_a_node_on_the_left_subtree_is_less_than_an_ancestor);
  add_test_with_context(suite, BinaryTree, when_a_node_on_the_right_subtree_is_greater_than_an_ancestor);
  add_test_with_context(suite, BinaryTree, when_the_tree_is_a_binary_search_tree);

  return suite;
}

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, binary_search_tree_tests());
  return run_test_suite(suite, create_text_reporter());
}

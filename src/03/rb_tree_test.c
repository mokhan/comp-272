#include "rb_tree.h"
#include <cgreen/cgreen.h>
#include <string.h>
/*
 * Every node has a colour. red or black
 * Root of the tree is always black.
 * There are no two adjacent red nodes. (red node cannot have red parent or child)
 * Every path from root to child NULL node has same # of black nodes.
 */

Ensure(one_equals_one) {
  assert_that(1, is_equal_to(1));
}

Ensure(initialize_returns_a_new_tree) {
  RBTree *tree = rb_tree_initialize(10);

  assert_that(tree, is_not_equal_to(NULL));
  assert_that(tree->value, is_equal_to(10));
  assert_that(tree->colour, is_equal_to(black));
}

TestSuite *rb_tree_tests() {
  TestSuite *x = create_test_suite();
  add_test(x, one_equals_one);
  add_test(x, initialize_returns_a_new_tree);
  return x;
}

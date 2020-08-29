#include "rb_tree.h"
#include <cgreen/cgreen.h>
#include <string.h>
/*
 * Every node has a colour. red or black
 * Root of the tree is always black.
 * There are no two adjacent red nodes. (red node cannot have red parent or child)
 * Every path from root to child NULL node has same # of black nodes.
 *
 *
 * 1. every node is coloured red or black.
 * 2. All leaves (nils) are black.
 * 3. Every red node has black children. black nodes can have any color children.
 * 4. From any node, the # of black nodes on any path to the leaves is the same. (same # of black nodes from top to bottom)

height: logn if perfectly balanced.

            (B)
          /     \
       (R)       (R)
      /   \     /   \
    (B)  (B)  (B)   (B)
   /  \
(nil) (nil)
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

Ensure(insert_returns_a_new_tree_when_null) {
  RBTree *tree = rb_tree_insert(NULL, 20);

  assert_that(tree, is_not_equal_to(NULL));
  assert_that(tree->value, is_equal_to(20));
  assert_that(tree->colour, is_equal_to(black));
}

Ensure(insert_adds_a_new_item_to_right_subtree) {
  RBTree *tree = rb_tree_initialize(10);

  tree = rb_tree_insert(tree, 20);

  assert_that(tree, is_not_equal_to(NULL));
  assert_that(tree->value, is_equal_to(10));
  assert_that(tree->colour, is_equal_to(black));
  assert_that(tree->right, is_not_equal_to(NULL));
  assert_that(tree->right->value, is_equal_to(20));
}

Ensure(insert_adds_a_new_item_to_left_subtree) {
  RBTree *tree = rb_tree_initialize(20);

  tree = rb_tree_insert(tree, 10);

  assert_that(tree, is_not_equal_to(NULL));
  assert_that(tree->value, is_equal_to(20));
  assert_that(tree->colour, is_equal_to(black));
  assert_that(tree->left, is_not_equal_to(NULL));
  assert_that(tree->left->value, is_equal_to(10));
}

TestSuite *rb_tree_tests() {
  TestSuite *x = create_test_suite();
  add_test(x, one_equals_one);
  add_test(x, initialize_returns_a_new_tree);
  add_test(x, insert_returns_a_new_tree_when_null);
  add_test(x, insert_adds_a_new_item_to_right_subtree);
  add_test(x, insert_adds_a_new_item_to_left_subtree);
  return x;
}

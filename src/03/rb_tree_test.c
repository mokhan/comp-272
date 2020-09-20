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

Ensure(rb_tree_insert_performs_a_right_rotation) {
/*
      (30)          (20:b)
      /            /    \
   (20)     ->  (10:r)    (30:r)
   /
(10)

*/
  RBTree *tree = rb_tree_initialize(30);

  tree = rb_tree_insert(tree, 20);
  tree = rb_tree_insert(tree, 10);

  assert_that(tree, is_not_equal_to(NULL));
  assert_that(tree->value, is_equal_to(20));
  assert_that(tree->colour, is_equal_to(black));

  assert_that(tree->left->value, is_equal_to(10));
  assert_that(tree->left->colour, is_equal_to(red));

  assert_that(tree->right->value, is_equal_to(30));
  assert_that(tree->right->colour, is_equal_to(red));
}

Ensure(rb_tree_insert_performs_a_left_rotation) {
/*
(10)                 (20:b)
   \                 /    \
   (20)     ->  (10:r)    (30:r)
     \
     (30)
*/

  RBTree *tree = rb_tree_initialize(10);
  tree = rb_tree_insert(tree, 20);
  tree = rb_tree_insert(tree, 30);

  assert_that(tree, is_not_equal_to(NULL));
  assert_that(tree->value, is_equal_to(20));
  assert_that(tree->colour, is_equal_to(black));
  assert_that(tree->left->value, is_equal_to(10));
  assert_that(tree->left->colour, is_equal_to(red));
  assert_that(tree->right->value, is_equal_to(30));
  assert_that(tree->right->colour, is_equal_to(red));
}

Ensure(rb_tree_insert_repaints_the_new_node) {
/*
     (20:b)                   (20:b)
     /    \                  /     \
  (10:r)  (30:r)  -->   (10:b)    (30:b)
  /                     /
(5:r)                 (5:r)
*/

  RBTree *tree = rb_tree_initialize(20);
  tree = rb_tree_insert(tree, 10);
  tree = rb_tree_insert(tree, 30);
  tree = rb_tree_insert(tree, 5);

  assert_that(tree, is_not_equal_to(NULL));
  assert_that(tree->value, is_equal_to(20));
  assert_that(tree->colour, is_equal_to(black));

  assert_that(tree->left->value, is_equal_to(10));
  assert_that(tree->left->colour, is_equal_to(black));

  assert_that(tree->left->left->value, is_equal_to(5));
  assert_that(tree->left->left->colour, is_equal_to(red));

  assert_that(tree->right->value, is_equal_to(30));
  assert_that(tree->right->colour, is_equal_to(black));
}

Ensure(rb_tree_insert_handles_large_trees) {
  RBTree *tree = NULL;
  int n = 100;

  for (int i = n; i > 0; i--)
    tree = rb_tree_insert(tree, i);

  assert_that(tree, is_not_equal_to(NULL));
  assert_that(tree->value, is_equal_to(69));
  assert_that(tree->colour, is_equal_to(black));

  assert_that(rb_tree_size(tree), is_equal_to(n));
}

Ensure(equals_returns_false_when_tree_is_NULL) {
  assert_that(rb_equals(NULL, rb_tree_initialize(10)), is_equal_to(false));
}

Ensure(equals_returns_false_when_other_tree_is_NULL) {
  assert_that(rb_equals(rb_tree_initialize(10), NULL), is_equal_to(false));
}

Ensure(equals_returns_true_when_both_trees_are_NULL) {
  assert_that(rb_equals(NULL, NULL), is_equal_to(true));
}

Ensure(equals_returns_false_when_tree_has_one_node) {
  RBTree *tree = rb_tree_initialize(20);
  RBTree *other_tree = rb_tree_initialize(10);

  assert_that(rb_equals(tree, other_tree), is_equal_to(false));
}

Ensure(equals_returns_false_when_tree_has_one_node_with_different_colours) {
  RBTree *tree = rb_tree_initialize(20);
  RBTree *other_tree = rb_tree_initialize(20);

  tree->colour = black;
  other_tree->colour = red;

  assert_that(rb_equals(tree, other_tree), is_equal_to(false));
}

Ensure(equals_returns_true_when_tree_has_one_node) {
  RBTree *tree = rb_tree_initialize(20);
  RBTree *other_tree = rb_tree_initialize(20);

  assert_that(rb_equals(tree, other_tree), is_equal_to(true));
}

Ensure(equals_returns_true_when_root_and_left_subtree_are_equal) {
  RBTree *tree = rb_tree_initialize(20);
  tree = rb_tree_insert(tree, 10);

  RBTree *other_tree = rb_tree_initialize(20);
  other_tree = rb_tree_insert(other_tree, 10);

  assert_that(rb_equals(tree, other_tree), is_equal_to(true));
}

Ensure(equals_returns_false_when_root_and_left_subtree_are_not_equal) {
  RBTree *tree = rb_tree_initialize(20);
  tree = rb_tree_insert(tree, 10);

  RBTree *other_tree = rb_tree_initialize(20);
  other_tree = rb_tree_insert(other_tree, 15);

  assert_that(rb_equals(tree, other_tree), is_equal_to(false));
}

Ensure(equals_returns_false_when_root_and_right_subtree_are_not_equal) {
  RBTree *tree = rb_tree_initialize(20);
  tree = rb_tree_insert(tree, 30);

  RBTree *other_tree = rb_tree_initialize(20);
  other_tree = rb_tree_insert(other_tree, 25);

  assert_that(rb_equals(tree, other_tree), is_equal_to(false));
}

Ensure(is_valid_returns_false_when_root_is_red) {
  RBTree *tree = rb_tree_initialize(20);
  tree->colour = red;

  assert_that(rb_tree_is_valid(tree), is_equal_to(false));
}

TestSuite *rb_tree_tests() {
  TestSuite *x = create_test_suite();

  add_test(x, initialize_returns_a_new_tree);

  add_test(x, insert_returns_a_new_tree_when_null);
  add_test(x, insert_adds_a_new_item_to_right_subtree);
  add_test(x, insert_adds_a_new_item_to_left_subtree);
  add_test(x, rb_tree_insert_performs_a_right_rotation);
  add_test(x, rb_tree_insert_performs_a_left_rotation);
  add_test(x, rb_tree_insert_repaints_the_new_node);
  add_test(x, rb_tree_insert_handles_large_trees);

  add_test(x, equals_returns_false_when_tree_is_NULL);
  add_test(x, equals_returns_false_when_other_tree_is_NULL);
  add_test(x, equals_returns_true_when_both_trees_are_NULL);
  add_test(x, equals_returns_false_when_tree_has_one_node);
  add_test(x, equals_returns_false_when_tree_has_one_node_with_different_colours);
  add_test(x, equals_returns_true_when_tree_has_one_node);
  add_test(x, equals_returns_true_when_root_and_left_subtree_are_equal);
  add_test(x, equals_returns_false_when_root_and_left_subtree_are_not_equal);
  add_test(x, equals_returns_false_when_root_and_right_subtree_are_not_equal);

  add_test(x, is_valid_returns_false_when_root_is_red);
  return x;
}

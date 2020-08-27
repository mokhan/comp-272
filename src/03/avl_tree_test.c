#include "avl_tree.h"
#include <cgreen/cgreen.h>
#include <string.h>

Ensure(initialize_returns_new_tree) {
  AVLTree *tree = avl_tree_initialize(1);
  assert_that(tree, is_not_equal_to(NULL));
}

Ensure(size_returns_zero) {
  AVLTree *tree = avl_tree_initialize(1);

  assert_that(avl_tree_size(tree), is_equal_to(1));
}

Ensure(insert_changes_size) {
  AVLTree *tree = avl_tree_initialize(5);
  avl_tree_insert(tree, 4);

  assert_that(avl_tree_size(tree), is_equal_to(2));
}

Ensure(insert_changes_height) {
  AVLTree *tree = avl_tree_initialize(5);
  tree = avl_tree_insert(tree, 4);

  assert_that(tree->height, is_equal_to(2));
  assert_that(tree->left->height, is_equal_to(1));
}

Ensure(insert_creates_a_new_root) {
  AVLTree *tree = avl_tree_insert(NULL, 10);

  assert_that(tree, is_not_equal_to(NULL));
  assert_that(tree->value, is_equal_to(10));
  assert_that(tree->left, is_equal_to(NULL));
  assert_that(tree->right, is_equal_to(NULL));
}

Ensure(insert_performs_a_left_rotation) {
/*
  (10)                  (20)
    \                  /    \
    (20)      ->    (10)    (30)
      \
      (30)
*/
  AVLTree *tree = avl_tree_initialize(10);
  tree = avl_tree_insert(tree, 20);
  tree = avl_tree_insert(tree, 30);

  assert_that(tree->value, is_equal_to(20));
  assert_that(tree->left->value, is_equal_to(10));
  assert_that(tree->right->value, is_equal_to(30));
};

Ensure(insert_performs_a_right_rotation) {
/*
     (30)            (20)
     /              /   \
   (20)     -->   (10)  (30)
   /
(10)
*/
  AVLTree *tree = avl_tree_initialize(30);
  tree = avl_tree_insert(tree, 20);
  tree = avl_tree_insert(tree, 10);

  assert_that(tree->value, is_equal_to(20));
  assert_that(tree->left->value, is_equal_to(10));
  assert_that(tree->right->value, is_equal_to(30));
}

Ensure(insert_performs_a_left_right_rotation) {
/*
   (30)         (20)
   /           /    \
(10)     -> (10)    (30)
   \
   (20)
*/
  AVLTree *tree = avl_tree_initialize(30);
  tree = avl_tree_insert(tree, 10);
  tree = avl_tree_insert(tree, 20);

  assert_that(tree->value, is_equal_to(20));
  assert_that(tree->left->value, is_equal_to(10));
  assert_that(tree->right->value, is_equal_to(30));
}

Ensure(insert_performs_a_right_left_rotation) {
/*
(10)             (20)
    \            /  \
    (30)  --> (10)  (30)
   /
 (20)
*/
  AVLTree *tree = avl_tree_initialize(10);
  tree = avl_tree_insert(tree, 30);
  tree = avl_tree_insert(tree, 20);

  assert_that(tree->value, is_equal_to(20));
  assert_that(tree->left->value, is_equal_to(10));
  assert_that(tree->right->value, is_equal_to(30));
}

TestSuite *avl_tree_tests() {
  TestSuite *x = create_test_suite();
  add_test(x, initialize_returns_new_tree);
  add_test(x, size_returns_zero);
  add_test(x, insert_changes_size);
  add_test(x, insert_changes_height);
  add_test(x, insert_creates_a_new_root);
  add_test(x, insert_performs_a_left_rotation);
  add_test(x, insert_performs_a_right_rotation);
  add_test(x, insert_performs_a_left_right_rotation);
  add_test(x, insert_performs_a_right_left_rotation);
  return x;
}

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, avl_tree_tests());
  return run_test_suite(suite, create_text_reporter());
}

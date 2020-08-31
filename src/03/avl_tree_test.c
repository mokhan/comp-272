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

Ensure(delete_handles_left_left_case) {
/*
      (z)                   (y)
      / \                /      \
    (y) (T4)          (X)        (z)
    / \       -->   /    \      /   \
  (x) (T3)        (T1)  (T2)  (T3)  (T4)
  / \
(T1) (T2)

Delete (37):

      (30)                           (20)
      /  \                         /      \
    (20) (35)                  (10)        (30)
    / \     \           -->   /    \      /   \
  (10) (25) *(37)            (5)  (15)  (25)  (35)
  / \
(5) (15)
*/

  AVLTree *tree = avl_tree_initialize(30);
  tree = avl_tree_insert(tree, 35);
  tree = avl_tree_insert(tree, 20);
  tree = avl_tree_insert(tree, 10);
  tree = avl_tree_insert(tree, 25);
  tree = avl_tree_insert(tree, 37);
  tree = avl_tree_insert(tree, 15);
  tree = avl_tree_insert(tree, 5);

  tree = avl_tree_delete(tree, 37);

  assert_that(tree, is_not_equal_to(NULL));
  assert_that(tree->value, is_equal_to(20));
  assert_that(tree->left->value, is_equal_to(10));
  assert_that(tree->left->left->value, is_equal_to(5));
  assert_that(tree->left->right->value, is_equal_to(15));

  assert_that(tree->right->value, is_equal_to(30));
  assert_that(tree->right->left->value, is_equal_to(25));
  assert_that(tree->right->right->value, is_equal_to(35));
}

Ensure(delete_handles_left_right_case) {
/*
      (z)                   (x)
      / \                 /     \
    (y) (T4)           (y)       (z)
    /  \        -->   /   \     /   \
  (T1)  (x)         (T1) (T2) (T3) (T4)
       /   \
    (T2)  (T3)

Delete (37):

      (30)                           (25)
      /  \                         /      \
    (20) (35)                  (20)        (30)
    / \     \           -->   /    \      /   \
  (10) (25) *(37)           (10)  (22)  (27)  (35)
        / \
      (22) (27)
*/
  AVLTree *tree = avl_tree_initialize(30);
  tree = avl_tree_insert(tree, 20);
  tree = avl_tree_insert(tree, 35);
  tree = avl_tree_insert(tree, 10);
  tree = avl_tree_insert(tree, 37);
  tree = avl_tree_insert(tree, 25);
  tree = avl_tree_insert(tree, 22);
  tree = avl_tree_insert(tree, 27);

  tree = avl_tree_delete(tree, 37);

  assert_that(tree, is_not_equal_to(NULL));
  assert_that(tree->value, is_equal_to(25));
  assert_that(tree->left->value, is_equal_to(20));
  assert_that(tree->left->left->value, is_equal_to(10));
  assert_that(tree->left->right->value, is_equal_to(22));

  assert_that(tree->right->value, is_equal_to(30));
  assert_that(tree->right->left->value, is_equal_to(27));
  assert_that(tree->right->right->value, is_equal_to(35));
}

Ensure(delete_handles_right_right_case) {
/*
      (z)                       (y)
      / \                    /       \
   (T4) (y)                (z)        (x)
        / \       -->     /   \      /   \
     (T3) (x)          (T4)  (T3)  (T2)  (T1)
          / \
       (T2) (T1)


      (20)                      (30)
      / \                    /       \
   (15) (30)               (20)      (35)
   /     / \      -->     /   \      /   \
*(10) (25) (35)        (15)  (25)  (33)  (37)
            / \
         (33) (37)
*/
  AVLTree *tree = avl_tree_initialize(20);

  tree = avl_tree_insert(tree, 30);
  tree = avl_tree_insert(tree, 15);
  tree = avl_tree_insert(tree, 10);
  tree = avl_tree_insert(tree, 20);
  tree = avl_tree_insert(tree, 25);
  tree = avl_tree_insert(tree, 35);
  tree = avl_tree_insert(tree, 33);
  tree = avl_tree_insert(tree, 37);

  tree = avl_tree_delete(tree, 10);

  assert_that(tree, is_not_equal_to(NULL));
  assert_that(tree->value, is_equal_to(30));

  assert_that(tree->left->value, is_equal_to(20));
  assert_that(tree->left->left->value, is_equal_to(15));
  assert_that(tree->left->right->value, is_equal_to(25));

  assert_that(tree->right->value, is_equal_to(35));
  assert_that(tree->right->left->value, is_equal_to(33));
  assert_that(tree->right->right->value, is_equal_to(37));
}

Ensure(delete_handles_right_left) {
/*
      (z)                       (x)
      /   \                   /       \
    (T4)  (y)               (z)       (y)
          / \              /  \      /   \
        (x) (T1)   -->  (T4)  (T3) (T2)  (T1)
        / \
    (T3) (T2)


      (20)                       (22)
      /   \                   /       \
    (15)  (25)               (20)      (25)
    /      / \              /  \      /   \
*(10)  (22)  (30)   -->  (15)  (21) (23)  (30)
      /  \
   (21)  (23)
*/

  AVLTree *tree = avl_tree_initialize(20);
  tree = avl_tree_insert(tree, 15);
  tree = avl_tree_insert(tree, 25);
  tree = avl_tree_insert(tree, 10);
  tree = avl_tree_insert(tree, 22);
  tree = avl_tree_insert(tree, 30);
  tree = avl_tree_insert(tree, 21);
  tree = avl_tree_insert(tree, 23);

  tree = avl_tree_delete(tree, 10);

  assert_that(tree, is_not_equal_to(NULL));
  assert_that(tree->value, is_equal_to(22));
  assert_that(tree->left->value, is_equal_to(20));
  assert_that(tree->left->left->value, is_equal_to(15));
  assert_that(tree->left->right->value, is_equal_to(21));

  assert_that(tree->right->value, is_equal_to(25));
  assert_that(tree->right->left->value, is_equal_to(23));
  assert_that(tree->right->right->value, is_equal_to(30));
}

Ensure(delete_handles_a_complicated_and_large_tree) {
  int items[] = { 44, 17, 62, 10, 32, 50, 78, 21, 48, 54, 72, 88, 45, 49, 52, 56, 81, 92 };
  unsigned int length = sizeof(items)/sizeof(items[0]);
  AVLTree *tree = NULL;

  for (int i = 0; i < length; i++)
    tree = avl_tree_insert(tree, items[i]);

  tree = avl_tree_delete(tree, 32);

  assert_that(tree->value, is_equal_to(62));
}

Ensure(delete_handles_a_complicated_and_small_tree) {
  int items[] = { 9, 1, 10, 0, 5, 11, -1, 2, 6 };
  unsigned int length = sizeof(items)/sizeof(items[0]);
  AVLTree *tree = NULL;

  for (int i = 0; i < length; i++)
    tree = avl_tree_insert(tree, items[i]);

  tree = avl_tree_delete(tree, 10);

  assert_that(tree->value, is_equal_to(1));
}

Ensure(delete_returns_a_null_root) {
  AVLTree *tree = avl_tree_delete(NULL, 10);

  assert_that(tree, is_equal_to(NULL));
}

Ensure(to_rb_tree_returns_a_new_red_black_tree) {
/*
        (20:3)                      (20:r)
        /    \          -->         /    \
    (15:2)    (30:2)           (15:b)    (30:b)
    /    \        \            /   \         \
(10:1) (17:1)     (35:1)  (10:r) (17:r)      (35:r)
 */
  AVLTree *tree = NULL;
  RBTree *expected = NULL;
  int items[] = { 20, 15, 30, 10, 17, 35};
  int length = sizeof(items) / sizeof(items[0]);

  for (int i = 0; i < length; i++) {
    tree = avl_tree_insert(tree, items[i]);
    expected = rb_tree_insert(expected, items[i]);
  }

  RBTree *rb_tree = avl_tree_to_rb_tree(tree);
  assert_that(rb_equals(expected, rb_tree), is_equal_to(true));
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

  add_test(x, delete_handles_left_left_case);
  add_test(x, delete_handles_left_right_case);
  add_test(x, delete_handles_right_right_case);
  add_test(x, delete_handles_right_left);
  add_test(x, delete_handles_a_complicated_and_large_tree);
  add_test(x, delete_handles_a_complicated_and_small_tree);
  add_test(x, delete_returns_a_null_root);

  add_test(x, to_rb_tree_returns_a_new_red_black_tree);
  return x;
}

TestSuite *rb_tree_tests();

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, avl_tree_tests());
  add_suite(suite, rb_tree_tests());
  return run_test_suite(suite, create_text_reporter());
}

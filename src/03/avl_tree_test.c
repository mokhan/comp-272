#include "avl_tree.h"
#include <cgreen/cgreen.h>
#include <string.h>

Ensure(initialize_returns_new_tree) {
  AVLTree *tree = avl_tree_init();
  assert_that(tree, is_not_equal_to(NULL));
}

Ensure(size_returns_zero) {
  AVLTree *tree = avl_tree_init();

  assert_that(avl_tree_size(tree), is_equal_to(0));
}

Ensure(insert_changes_size) {
  AVLTree *tree = avl_tree_init();
  avl_tree_insert(tree, 33);

  assert_that(avl_tree_size(tree), is_equal_to(1));
}

TestSuite *avl_tree_tests() {
  TestSuite *suite = create_test_suite();
  add_test(suite, initialize_returns_new_tree);
  add_test(suite, size_returns_zero);
  add_test(suite, insert_changes_size);
  return suite;
}

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, avl_tree_tests());
  return run_test_suite(suite, create_text_reporter());
}

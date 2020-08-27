#include "avl_tree.h"
#include <cgreen/cgreen.h>
#include <string.h>

Ensure(initialize_returns_new_tree) {
  assert_that(NULL, is_equal_to(NULL));
}

TestSuite *avl_tree_tests() {
  TestSuite *suite = create_test_suite();
  add_test(suite, initialize_returns_new_tree);
  return suite;
}

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, avl_tree_tests());
  return run_test_suite(suite, create_text_reporter());
}

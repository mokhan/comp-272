#include "rb_tree.h"
#include <cgreen/cgreen.h>
#include <string.h>

Ensure(one_equals_one) {
  assert_that(1, is_equal_to(1));
}

TestSuite *rb_tree_tests() {
  TestSuite *x = create_test_suite();
  add_test(x, one_equals_one);
  return x;
}

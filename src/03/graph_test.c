#include "graph.h"
#include <cgreen/cgreen.h>
#include <string.h>

Ensure(three_equals_three) {
  assert_that(3, is_equal_to(3));
}

TestSuite *graph_tests() {
  TestSuite *x = create_test_suite();

  add_test(x, three_equals_three);

  return x;
}

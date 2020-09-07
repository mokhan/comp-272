#include "graph.h"
#include <cgreen/cgreen.h>
#include <string.h>

Ensure(three_equals_three) {
  assert_that(3, is_equal_to(3));
}

Ensure(initialize_returns_a_new_vertex) {
  Vertex *a = graph_initialize('a');

  assert_that(a, is_not_equal_to(NULL));
}

TestSuite *graph_tests() {
  TestSuite *x = create_test_suite();

  add_test(x, three_equals_three);

  return x;
}

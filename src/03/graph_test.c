#include "graph.h"
#include <cgreen/cgreen.h>
#include <string.h>

Ensure(three_equals_three) {
  assert_that(3, is_equal_to(3));
}

Ensure(initialize_returns_a_new_vertex) {
  Graph *graph = graph_initialize();

  assert_that(graph, is_not_equal_to(NULL));
}

Ensure(add_vertex_returns_a_new_vertex) {
  Graph *graph = graph_initialize();
  char label = 'a';
  Vertex *a = graph_add_vertex(graph, label);

  assert_that(a, is_not_equal_to(NULL));
  assert_that(graph->vertices[(int)label], is_equal_to(a));
}

TestSuite *graph_tests() {
  TestSuite *x = create_test_suite();

  add_test(x, three_equals_three);

  add_test(x, initialize_returns_a_new_vertex);

  add_test(x, add_vertex_returns_a_new_vertex);

  return x;
}

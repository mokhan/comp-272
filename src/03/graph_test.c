#include "graph.h"
#include <cgreen/cgreen.h>
#include <string.h>

Ensure(initialize_returns_a_new_graph) {
  Graph *graph = graph_initialize();

  assert_that(graph, is_not_equal_to(NULL));
  for (int i = 0; i < 128; ++i)
    assert_that(graph->vertices[i], is_equal_to(NULL));
}

Ensure(add_vertex_returns_a_new_vertex) {
  Graph *graph = graph_initialize();
  char label = 'a';
  Vertex *a = graph_add_vertex(graph, label);

  assert_that(a, is_not_equal_to(NULL));
  assert_that(graph->vertices[(int)label], is_equal_to(a));
}

Ensure(add_vertex_adds_max_number_of_verticies_to_graph) {
  Graph *graph = graph_initialize();

  for (int i = 0; i < 128; ++i) {
    Vertex *item = graph_add_vertex(graph, (char)i);
    assert_that(item, is_not_equal_to(NULL));
    assert_that(graph->vertices[i], is_equal_to(item));
  }
}

Ensure(add_edge_connects_two_vertices) {
  Graph *graph = graph_initialize();

  graph_add_edge(graph, graph_add_vertex(graph, 'a'),
                 graph_add_vertex(graph, 'b'));

  assert_that(graph->edges['a']['b'], is_equal_to(true));
  assert_that(graph->edges['b']['a'], is_equal_to(false));
}

Ensure(has_edge_returns_true) {
  Graph *graph = graph_initialize();
  Vertex *a = graph_add_vertex(graph, 'a');
  Vertex *b = graph_add_vertex(graph, 'b');

  graph_add_edge(graph, a, b);

  assert_that(graph_has_edge(graph, a, b), is_equal_to(true));
}

Ensure(has_edge_returns_false) {
  Graph *graph = graph_initialize();
  Vertex *a = graph_add_vertex(graph, 'a');
  Vertex *b = graph_add_vertex(graph, 'b');
  Vertex *c = graph_add_vertex(graph, 'c');

  graph_add_edge(graph, a, b);

  assert_that(graph_has_edge(graph, a, c), is_equal_to(false));
}

TestSuite *graph_tests() {
  TestSuite *x = create_test_suite();

  add_test(x, add_edge_connects_two_vertices);
  add_test(x, add_vertex_adds_max_number_of_verticies_to_graph);
  add_test(x, add_vertex_returns_a_new_vertex);
  add_test(x, has_edge_returns_true);
  add_test(x, has_edge_returns_false);
  add_test(x, initialize_returns_a_new_graph);

  return x;
}

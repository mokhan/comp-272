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

  graph_add_edge(
    graph,
    graph_add_vertex(graph, 'a'),
    graph_add_vertex(graph, 'b')
  );

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
int graph[16][16] = {
  {0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0},
  {0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
  {1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0},
  {0,0,0,1,0,0,0,1,0,1,1,0,0,0,0,0},
  {0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0},
  {0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0},
  {0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1},
  {0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0},
};
char labels[16] = {
  'a', 'b', 'c', 'd',
  'e', 'f', 'g', 'h',
  'i', 'j', 'k', 'l',
  'm', 'n', 'o', 'p'
};
int visited[16] = {0};

void traverse(int vertex) {
  printf("->(%c)", labels[vertex]);
  visited[vertex] = 1;

  for (int edge = 0; edge < 16; ++edge) {
    if (!visited[edge] && graph[vertex][edge] > 0) {
      graph[vertex][edge] = 0;
      traverse(edge);
      graph[edge][vertex] = 0;
      printf("->(%c)", labels[vertex]);
    }
  }
  for (int edge = 0; edge < 16; ++edge) {
    if (graph[vertex][edge] > 0 && graph[edge][vertex] > 0) {
      graph[vertex][edge] = 0;
      traverse(edge);
      graph[edge][vertex] = 0;
      printf("->(%c)", labels[vertex]);
    }
  }
}

void graph_inspect(int n) {
  printf("\n");

  printf("| ");
  for (int i = 0; i < n; ++i)
    printf("|%c", labels[i]);
  printf("|\n");

  for (int i = 0; i < n; ++i) {
    printf("|%c|", labels[i]);
    for (int j = 0; j < n; ++j)
      printf("%d|", graph[i][j]);
    printf("\n");
  }
}

Ensure(every_edge_is_traversed_in_both_directions_at_least_once) {
  int n = 16;

  traverse(0);
  graph_inspect(n);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      assert_that(graph[i][j], is_equal_to(0));
}

TestSuite *graph_tests() {
  TestSuite *x = create_test_suite();

  add_test(x, add_edge_connects_two_vertices);
  add_test(x, add_vertex_adds_max_number_of_verticies_to_graph);
  add_test(x, add_vertex_returns_a_new_vertex);
  add_test(x, has_edge_returns_true);
  add_test(x, has_edge_returns_false);
  add_test(x, initialize_returns_a_new_graph);

  add_test(x, every_edge_is_traversed_in_both_directions_at_least_once);
  return x;
}

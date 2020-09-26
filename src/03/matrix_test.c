#include "matrix.h"
#include <cgreen/cgreen.h>
#include <string.h>

Ensure(every_edge_is_traversed_in_both_directions_at_least_once) {
  int n = 16;
  int visited[16] = {0};
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

  matrix_inspect(n, graph);
  matrix_traverse(n, graph, visited, 0);
  matrix_inspect(n, graph);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      assert_that(graph[i][j], is_equal_to(0));
}

TestSuite *matrix_tests() {
  TestSuite *x = create_test_suite();

  add_test(x, every_edge_is_traversed_in_both_directions_at_least_once);

  return x;
}

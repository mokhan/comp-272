#include <stdio.h>
#include <stdlib.h>

char labels[26] = {
  'a', 'b', 'c', 'd',
  'e', 'f', 'g', 'h',
  'i', 'j', 'k', 'l',
  'm', 'n', 'o', 'p',
  'q', 'r', 's', 't',
  'u', 'v', 'w', 'x',
  'y', 'z'
};

void matrix_traverse(int n, int graph[n][n], int visited[n], int vertex) {
  printf("->(%c)", labels[vertex]);
  visited[vertex] = 1;

  for (int edge = 0; edge < n; ++edge) {
    if (!visited[edge] && graph[vertex][edge] > 0) {
      graph[vertex][edge] = 0;
      matrix_traverse(n, graph, visited, edge);
      graph[edge][vertex] = 0;
      printf("->(%c)", labels[vertex]);
    }
  }
  for (int edge = 0; edge < n; ++edge) {
    if (graph[vertex][edge] > 0 && graph[edge][vertex] > 0) {
      graph[vertex][edge] = 0;
      matrix_traverse(n, graph, visited, edge);
      graph[edge][vertex] = 0;
      printf("->(%c)", labels[vertex]);
    }
  }
}

void matrix_inspect(int n, int graph[n][n]) {
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

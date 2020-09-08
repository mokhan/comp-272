#include <stdbool.h>

typedef struct {
  char label;
} Vertex;

typedef struct {
  Vertex *vertices[128];
  bool edges[128][128];
} Graph;

Graph *graph_initialize(void);
Vertex *graph_add_vertex(Graph *graph, char label);
void graph_add_edge(Graph *graph, Vertex *a, Vertex *b);

#include "graph.h"
#include <stdlib.h>

Vertex *vertex_initialize(char label) {
  Vertex *item = malloc(sizeof(Vertex));
  item->label = label;
  return item;
};

Graph *graph_initialize(void) {
  Graph *item = malloc(sizeof(Graph));
  for (int i = 0; i < 256; ++i)
    item->vertices[i] = NULL;
  return item;
}

Vertex *graph_add_vertex(Graph *graph, char label) {
  Vertex *item = vertex_initialize(label);
  graph->vertices[(int)label] = item;
  return item;
}

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

Vertex *vertex_initialize(char label) {
  Vertex *item = malloc(sizeof(Vertex));
  item->label = label;
  return item;
};

Graph *graph_initialize(void) {
  Graph *item = malloc(sizeof(Graph));
  for (int i = 0; i < 128; ++i)
    item->vertices[i] = NULL;
  return item;
}

Vertex *graph_add_vertex(Graph *graph, char label) {
  Vertex *item = vertex_initialize(label);
  graph->vertices[(int)label] = item;
  return item;
}

void graph_add_edge(Graph *graph, Vertex *a, Vertex *b) {
  graph->edges[a->label][b->label] = true;
}

bool graph_has_edge(Graph *graph, Vertex *a, Vertex *b) {
  return graph->edges[a->label][b->label];
}

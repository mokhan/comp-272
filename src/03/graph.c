#include "graph.h"
#include <stdlib.h>

Vertex *graph_initialize(char label) {
  Vertex *item = malloc(sizeof(Vertex));
  item->label = label;
  return item;
};

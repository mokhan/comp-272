#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Creates a new Vertex for use in a Graph.
 *
 * @param label The label to attach to the node.
 * @return Returns a new vertex
 */
Vertex *vertex_initialize(char label) {
  Vertex *item = malloc(sizeof(Vertex));
  item->label = label;
  return item;
};

/**
 * Initializes a new Graph
 *
 * @return Returns a new instance of a Graph.
 */
Graph *graph_initialize(void) {
  Graph *item = malloc(sizeof(Graph));
  for (int i = 0; i < 128; ++i)
    item->vertices[i] = NULL;
  return item;
}

/**
 * Inserts a new vertex into a graph with the provided label.
 *
 * @param graph The graph to insert a new vertex into
 * @param label The label to apply to the new vertex.
 * @return Returns the new vertex
 */
Vertex *graph_add_vertex(Graph *graph, char label) {
  Vertex *item = vertex_initialize(label);
  graph->vertices[(int)label] = item;
  return item;
}

/**
 * Updates a adjacency matrix to indicate that an edge exists
 * between two vertexes.
 *
 * @param graph The graph to modify.
 * @param a The vertex that points to vertex b.
 * @param b The vertex that vertex a points to.
 */
void graph_add_edge(Graph *graph, Vertex *a, Vertex *b) {
  graph->edges[a->label][b->label] = true;
}

/**
 * Returns true or false to specify if vertex `a`
 * in a graph is connected to vertex `b` in the same
 * graph.
 *
 * @param graph The graph to investigate
 * @param a The starting vertext to check
 * @param b The vertex that vertex a might be pointing at.
 * @return Returns true if an edge exists between the two vertexes otherwise
 * false.
 */
bool graph_has_edge(Graph *graph, Vertex *a, Vertex *b) {
  return graph->edges[a->label][b->label];
}

typedef struct {
  char label;
} Vertex;

typedef struct {
  Vertex *vertices[128];
} Graph;

Graph *graph_initialize(void);
Vertex *graph_add_vertex(Graph *graph, char label);

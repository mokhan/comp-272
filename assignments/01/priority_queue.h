typedef struct {
  int priority;
  int data;
} Node;

typedef struct {
  int size;
} PriorityQueue;


PriorityQueue *initialize();
Node *create_node(int priority, int data);
int count(PriorityQueue *queue);
void add(PriorityQueue *queue, Node *node);

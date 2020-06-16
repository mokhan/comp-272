typedef struct {

} Node;

typedef struct {
  int size;
} PriorityQueue;


PriorityQueue *initialize();
int count(PriorityQueue *queue);
void add(PriorityQueue *queue, Node *node);

struct node {
  int priority;
  int data;
  struct node *next;
};

typedef struct node Node;

typedef struct {
  Node *head;
  int size;
} PriorityQueue;

PriorityQueue *initialize();
Node *create_node(int priority, int data);
int count(PriorityQueue *queue);
void add(PriorityQueue *queue, Node *node);
Node *delete_min(PriorityQueue *queue);
void inspect(PriorityQueue *queue);

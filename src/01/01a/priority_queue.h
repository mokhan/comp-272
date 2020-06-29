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
int size(PriorityQueue *queue);
void add(PriorityQueue *queue, int priority, int data);
Node *delete_min(PriorityQueue *queue);
void destroy(PriorityQueue *queue);

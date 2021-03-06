/**
 * A struct that represents a single node in a linked list
 */
struct node {
  int priority;
  int data;
  struct node *next;
};

typedef struct node Node;

/**
 * A struct that represents a Queue implemented using a Singly Linked List.
 */
typedef struct {
  Node *head;
  int size;
} PriorityQueue;

PriorityQueue *initialize(void);
int size(PriorityQueue *queue);
void add(PriorityQueue *queue, int priority, int data);
int delete_min(PriorityQueue *queue);
void destroy(PriorityQueue *queue);
void inspect(PriorityQueue *queue);

/**
 * A singly linked list node node
 */
struct node {
  int data;
  struct node *next;
};

typedef struct node Node;

/**
 * A queue
 */
typedef struct {
  Node *head;
  int size;
} Queue;

/**
 * A stack
 */
typedef struct {
  Queue *q1;
} Stack;

Stack *initialize(void);
void push(Stack *stack, int data);
int pop(Stack *stack);
int size(Stack *stack);
void destroy(Stack *stack);

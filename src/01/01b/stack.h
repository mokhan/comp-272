struct node {
  int data;
  struct node *next;
};

typedef struct node Node;

typedef struct {
  Node *head;
  int size;
} Queue;

typedef struct {
  Queue *q1;
} Stack;


Stack *initialize();
void push(Stack *stack, int data);
int pop(Stack *stack);
int size(Stack *stack);
void destroy(Stack *stack);

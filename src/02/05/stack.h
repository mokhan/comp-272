typedef struct node {
  struct node *next;
  int data;
} Node;

typedef struct {
  Node *head;
} Stack;

Stack *stack_init(int data);
int stack_size(Stack *self);
int stack_peek(Stack *self);

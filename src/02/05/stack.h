typedef struct node {
  struct node *next;
  int data;
} Node;

typedef struct {
  Node *head;
} Stack;

Stack *stack_init();
int stack_peek(Stack *self);
int stack_size(Stack *self);
void stack_push(Stack *self, int data);
int stack_pop(Stack *self);

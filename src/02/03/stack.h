#include "node.h"

typedef struct {
  Node *head;
} Stack;

Stack *stack_init();
void *stack_peek(Stack *self);
int stack_size(Stack *self);
void stack_push(Stack *self, void *data);
void *stack_pop(Stack *self);

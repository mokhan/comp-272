#include "stack.h"
#include <stdlib.h>

Node *node_init(int data) {
  Node *node = malloc(sizeof(Node));
  node->next = NULL;
  node->data = data;
  return node;
}

Stack *stack_init(int data) {
  Stack *stack = malloc(sizeof(Stack));
  stack->head = node_init(data);
  return stack;
}

int stack_size(Stack *self) {
  if (!self || !self->head)
    return 0;

  int count;
  Node *current = self->head;
  while (current) {
    ++count;
    current = current->next;
  }

  return count;
}

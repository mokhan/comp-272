#include "stack.h"
#include <stdlib.h>

Node *node_init(void *data) {
  Node *node = malloc(sizeof(Node));
  node->next = NULL;
  node->data = data;
  return node;
}

Stack *stack_init() {
  Stack *stack = malloc(sizeof(Stack));
  stack->head = NULL;
  return stack;
}

int stack_size(Stack *self) {
  if (!self || !self->head)
    return 0;

  int count = 0;
  Node *current = self->head;
  while (current) {
    ++count;
    current = current->next;
  }

  return count;
}

void *stack_peek(Stack *self) {
  if (self->head)
    return self->head->data;
  return NULL;
}

void stack_push(Stack *stack, void *data) {
  Node *node = node_init(data);
  node->next = stack->head;
  stack->head = node;
}

void *stack_pop(Stack *self) {
  if (self->head) {
    Node *tmp = self->head;
    void *data = tmp->data;
    self->head = self->head->next;
    free(tmp);
    return data;
  }
  return NULL;
}

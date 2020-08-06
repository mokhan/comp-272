#include "stack.h"
#include <stdlib.h>

Node *node_init(int data) {
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

  int count;
  Node *current = self->head;
  while (current) {
    ++count;
    current = current->next;
  }

  return count;
}

int stack_peek(Stack *self) {
  if (self->head)
    return self->head->data;
  return -1;
}

void stack_push(Stack *stack, int data) {
  Node *node = node_init(data);
  node->next = stack->head;
  stack->head = node;
}

int stack_pop(Stack *self) {
  if (self->head) {
    Node *tmp = self->head;
    int data = tmp->data;
    self->head = self->head->next;
    free(tmp);
    return data;
  }
  return -1;
}

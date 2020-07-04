#include <stdio.h>
#include <stdlib.h>
#include "min_stack.h"

Stack *initialize() {
  Stack *self = malloc(sizeof(Stack));
  self->head = NULL;
  return self;
}

int size(Stack *self) {
  Node *current = self->head;
  int i;
  for (i = 0; current != NULL; i++)
    current = current->next;
  return i;
}

static Node *new(int data) {
  Node *node = malloc(sizeof(Node));
  node->next = NULL;
  node->data = data;
  return node;
}

static int compare(int x, int y) {
  return x == y ? 0 : (x > y) ? 1 : -1;
}

static void insert(Node **self, int data) {
  int comparison = compare(data, (*self)->data);
  Node *node = new(data);

  switch(comparison) {
    case 1:
      if ((*self)->next)
        insert(&((*self)->next), data);
      else
        (*self)->next = node;
      break;
    default:
      node->next = *self;
      *self = node;
      break;
  }
}

void push(Stack *self, int data) {
  if (self->head)
    insert(&self->head, data);
  else
    self->head = new(data);
}

int min(Stack *self) {
  if (self && self->head)
    return self->head->data;

  return (int)NULL;
}

int pop(Stack *self) {
  if (!self->head)
    return (int)NULL;

  Node *current = self->head;
  int data = current->data;
  self->head = current->next;
  current->next = NULL;
  free(current);
  return data;
}

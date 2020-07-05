#include <stdio.h>
#include <stdlib.h>
#include "min_stack.h"

static Node *new(int data, Node *next) {
  Node *node = malloc(sizeof(Node));
  node->next = next;
  node->data = data;
  return node;
}

Stack *initialize(void) {
  Stack *self = malloc(sizeof(Stack));
  self->head = NULL;
  self->min = NULL;
  self->size = 0;
  return self;
}

int size(Stack *self) {
  return self->size;
}

void push(Stack *self, int data) {
  if (!self->min || (data < self->min->data))
    self->min = new(data, self->min);

  self->head = new(data, self->head);
  self->size++;
}

void each(Node *head, Visitor block) {
  Node *tmp = head;

  while(tmp) {
    (*block)(tmp);
    tmp = tmp->next;
  }
}

int min(Stack *self) {
  if(self->min)
    return self->min->data;

  if (self->head) {
    int min = self->head->data;
    Node *tmp = self->head->next;

    while(tmp) {
      if (tmp->data < min)
        min = tmp->data;
      tmp = tmp->next;
    }
    return min;
  }

  return (int)NULL;
}

int pop(Stack *self) {
  if (!self->head)
    return (int)NULL;

  Node *current = self->head;
  int data = current->data;
  if (data == self->min->data)
    self->min = self->min->next;
  self->head = current->next;
  self->size--;
  current->next = NULL;
  free(current);
  return data;
}

void print_node(Node *node) {
  printf("[%d]", node->data);
}

void inspect(Stack *stack) {
  printf("\t");
  each(stack->head, &print_node);
  printf("\n");
}

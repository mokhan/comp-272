#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Node *initialize(int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

Node *add(Node *head, int data) {
  Node *tail;
  Node *tmp = head;

  while(tmp) {
    if (!tmp->next)
      break;
    tmp = tmp->next;
  }
  tail = tmp;
  tail->next = initialize(data);
  tail->next->prev = tail;
  return tail->next;
}

Node *get(Node *from, int index) {
  if (!from || index < 0) return NULL;

  while(index > 0 && from){
    from = from->next;
    index--;
  }
  return from;
}

static int size(Node *head) {
  int i = 0;
  for (Node *tmp = head; tmp && tmp != NULL; tmp = tmp->next) i++;
  return i;
}

static void assign_next(Node *self, Node *other) {
  if (self)
    self->next = other;

  if (other)
    other->prev = self;
}

static void assign_prev(Node *self, Node *other) {
  if (self)
    self->prev = other;

  if (other)
    other->next = self;
}

Node *reverse(Node *head) {
  Node *tmp = NULL;
  Node *current = head;

  while (current != NULL) {
    tmp = current->prev;
    current->prev = current->next;
    current->next = tmp;
    current = current->prev;
  }
  return tmp ? tmp->prev : head;
}

static void print(Node *node) {
  if (node->prev && node->next)
    printf("(%d<%d>%d)", node->prev->data, node->data, node->next->data);
  else if (node->next)
    printf("(nil<%d>%d)", node->data, node->next->data);
  else
    printf("(%d<%d>nil)", node->prev->data, node->data);
}

void inspect(Node *node) {
  if (!node) return;

  printf("[ ");
  while (node) {
    print(node);
    printf(" ");
    node = node->next;
  }
  printf("]\n");
}


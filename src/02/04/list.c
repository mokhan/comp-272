#include "list.h"
#include <stdio.h>
#include <stdlib.h>

Node *list_initialize(void *data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

Node *list_add(Node *head, void *data) {
  Node *tail;
  Node *tmp = head;

  while (tmp) {
    if (!tmp->next)
      break;
    tmp = tmp->next;
  }
  tail = tmp;
  tail->next = list_initialize(data);
  return tail->next;
}

Node *list_get(Node *self, int index) {
  if (!self || index < 0)
    return NULL;

  while (index > 0 && self) {
    self = self->next;
    index--;
  }
  return self;
}

int list_size(Node *head) {
  int i = 0;
  for (Node *tmp = head; tmp && tmp != NULL; tmp = tmp->next)
    i++;
  return i;
}

void list_inspect(Node *self, Printer printer) {
  if (!self)
    return;

  printf("[");
  while (self) {
    printer(self->data);
    /*printf(" %p ", self->data);*/
    self = self->next;
  }
  printf("]\n");
}

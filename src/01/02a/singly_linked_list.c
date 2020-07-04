#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

static void inspect(Node *node) {
  if (!node) return;

  printf("*******\n");
  while (node) {
    printf("\t%d\n", node->data);
    node = node->next;
  }
  printf("*******\n");
}

Node *initialize(int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
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

void swap(Node **head, int x, int y) {
  int count = size(*head);

  if (x == y) return;
  if (x >= count) return;
  if (y >= count) return;

  Node *xp = get(*head, x - 1);
  Node *yp = get(*head, y - 1);
  Node *xc = get(*head, x);
  Node *yc = get(*head, y);

  if (x == 0)
    *head = yc;
  else
    xp->next = yc;

  if (y == 0)
    *head = xc;
  else
    yp->next = xc;

  Node *tmp = yc->next;
  yc->next = xc->next;
  xc->next = tmp;
}

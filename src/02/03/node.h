#ifndef NODE_H
#define NODE_H

typedef struct node {
  struct node *next;
  void *data;
} Node;

#endif

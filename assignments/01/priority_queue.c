#include "priority_queue.h"
#include <stdlib.h>

PriorityQueue *initialize() {
  PriorityQueue *queue = malloc(sizeof(PriorityQueue));
  queue->size = 0;
  return queue;
}
Node *create_node(int priority, int data) {
  Node *node = malloc(sizeof(Node));
  node->priority = priority;
  node->data = data;
  return node;
}

int count(PriorityQueue *queue) {
  return queue->size;
}

void add(PriorityQueue *queue, Node *node) {
  queue->size++;
}

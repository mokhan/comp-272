#include "priority_queue.h"
#include <stdlib.h>

PriorityQueue *initialize() {
  PriorityQueue *queue = malloc(sizeof(PriorityQueue));
  queue->size = 0;
  return queue;
}

int count(PriorityQueue *queue) {
  return queue->size;
}

void add(PriorityQueue *queue, Node *node) {
  queue->size++;
}

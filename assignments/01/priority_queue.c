#include "priority_queue.h"
#include <stdlib.h>

PriorityQueue *initialize() {
  PriorityQueue *queue = malloc(sizeof(PriorityQueue));
  queue->size = 0;
  queue->head = NULL;
  return queue;
}

Node *create_node(int priority, int data) {
  Node *node = malloc(sizeof(Node));
  node->priority = priority;
  node->data = data;
  node->next = NULL;
  return node;
}

int count(PriorityQueue *queue) {
  return queue->size;
}

void add(PriorityQueue *queue, Node *node) {
  queue->size++;

  if (queue->head == NULL) {
    queue->head = node;
    return;
  }

  Node *tmp = queue->head;

  while(tmp != NULL) {
    if (tmp->data > node->data) {
      tmp->next = node;
      if (tmp == queue->head) {
        queue->head = node;
      }
      break;
    }
    tmp = tmp->next;
  }
}

Node *delete_min(PriorityQueue *queue) {
  return queue->head;
}

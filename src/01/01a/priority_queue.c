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

// This function is constant time O(1)
int size(PriorityQueue *queue) {
  return queue->size;
}

// This function is linear time O(n)
void add(PriorityQueue *queue, int priority, int data) {
  Node *node = create_node(priority, data);
  queue->size++;

  if (queue->head == NULL) {
    queue->head = node;
    return;
  }

  Node *tmp = queue->head;
  Node *prev = NULL;

  while(tmp != NULL) {
    if (tmp->data > node->data) {
      node->next = tmp;
      if (tmp == queue->head)
        queue->head = node;
      else if (prev != NULL)
        prev->next = node;
      break;
    }
    prev = tmp;
    tmp = tmp->next;
  }
}

// This function is constant time O(1)
int delete_min(PriorityQueue *queue) {
  if (queue->head) {
    Node *tmp = queue->head;
    int data = tmp->data;
    queue->head = tmp->next;
    queue->size--;
    free(tmp);
    return data;
  }
  return 0;
}

void destroy(PriorityQueue *queue) {
  Node *current = queue->head;
  Node *tmp;

  while(current) {
    tmp = current, current = current->next;

    if (tmp) free(tmp);
  }
  free(queue);
}

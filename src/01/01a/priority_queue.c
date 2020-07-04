#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

PriorityQueue *initialize() {
  PriorityQueue *queue = malloc(sizeof(PriorityQueue));
  queue->size = 0;
  queue->head = NULL;
  return queue;
}

static Node *create_node(int priority, int data) {
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

static int compare(const int x, const int y) {
  return x == y ? 0 : x > y ? 1 : -1;
}

void enqueue(Node *self, int priority, int data) {
  if (self->next == NULL) {
    self->next = create_node(priority, data);
    return;
  }

  int comparison = compare(self->next->priority, priority);
  if (comparison == 0) {
    return enqueue(self->next, priority, data);
  }

  if (comparison < 0) {
    return enqueue(self->next, priority, data);
  }

  Node *tmp = self->next;
  self->next = create_node(priority, data);
  self->next->next = tmp;
}

// This function is linear time O(n)
void add(PriorityQueue *queue, int priority, int data) {
  queue->size++;

  if (!queue->head) {
    queue->head = create_node(priority, data);
    return;
  }

  if (compare(queue->head->priority, priority) <= 0)
    return enqueue(queue->head, priority, data);

  Node *node = create_node(priority, data);
  node->next = queue->head;
  queue->head = node;
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

void inspect(PriorityQueue *queue) {
  Node *tmp = queue->head;

  printf("Items (%d): [ ", size(queue));
  while(tmp) {
    printf("(%d,%d) ", tmp->priority, tmp->data);
    tmp = tmp->next;
  }
  printf("]\n");
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

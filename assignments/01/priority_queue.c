#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

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

Node *delete_min(PriorityQueue *queue) {
  Node *tmp = queue->head;
  queue->head = tmp->next;
  return tmp;
}

void inspect(PriorityQueue *queue) {
  Node *tmp = queue->head;

  printf("*******\n");
  while(tmp) {
    printf("%d\n", tmp->data);
    tmp = tmp->next;
  }
  printf("*******\n");
}

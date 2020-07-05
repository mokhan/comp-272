#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * The equivalent of a constructor to create a PriorityQueue.
 */
PriorityQueue *initialize(void) {
  PriorityQueue *self = malloc(sizeof(PriorityQueue));
  self->size = 0;
  self->head = NULL;
  return self;
}

/**
 * A function used to construct a Node for a singly linked list.
 *
 * @param priority the priority for the data
 * @param data the data to store in the queue
 * @return The Node to add to a singly linked list.
 */
static Node *create_node(int priority, int data) {
  Node *node = malloc(sizeof(Node));
  node->priority = priority;
  node->data = data;
  node->next = NULL;
  return node;
}

/**
 * Determines the number of items stored in a queue.
 *
 * @param self The queue to investigate
 * @return The total number of items stored in the queue.
 */
int size(PriorityQueue *self) { return self->size; }

/**
 * Compares two integers and returns:
 * 1 if x is greater than y.
 * 0 if x is equal to y.
 * -1 if x is less than to y.
 *
 *  @param x the integer to compare
 *  @param y the other integer to compare
 *  @return 1,0,-1 depending on the comparison of x and y
 */
static int compare(const int x, const int y) {
  return x == y ? 0 : x > y ? 1 : -1;
}

/**
 * Inserts a node into the queue in the best position based on the priority.
 *
 * @param self The head of the queue.
 * @param priority The priority of the data.
 * @param data the data to store.
 */
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

/**
 * Adds data with a specific priority to the queue
 *
 * @param self The queue to add data to
 * @param priority The priority for the data
 * @param data The data to store
 */
void add(PriorityQueue *self, int priority, int data) {
  self->size++;

  if (!self->head) {
    self->head = create_node(priority, data);
    return;
  }

  if (compare(self->head->priority, priority) <= 0)
    return enqueue(self->head, priority, data);

  Node *node = create_node(priority, data);
  node->next = self->head;
  self->head = node;
}

/**
 * Removes the next item in the queue with the lowest priority.
 *
 * @param self The queue
 * @return The data associated with the lowest priority in the queue
 */
int delete_min(PriorityQueue *self) {
  if (self->head) {
    Node *tmp = self->head;
    int data = tmp->data;
    self->head = tmp->next;
    self->size--;
    free(tmp);
    return data;
  }
  return 0;
}

/**
 * A helper function used to print a queue.
 * This is useful for debugging.
 *
 * @param self The queue to print
 */
void inspect(PriorityQueue *self) {
  Node *tmp = self->head;

  printf("Items (%d): [ ", size(self));
  while (tmp) {
    printf("(%d,%d) ", tmp->priority, tmp->data);
    tmp = tmp->next;
  }
  printf("]\n");
}

/**
 * The equivalent of a destructor function.
 * This function frees any memory associated with a queue
 *
 * @param self The queue to free
 */
void destroy(PriorityQueue *self) {
  Node *current = self->head;
  Node *tmp;

  while (current) {
    tmp = current, current = current->next;

    if (tmp)
      free(tmp);
  }
  free(self);
}

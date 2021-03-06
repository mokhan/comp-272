#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Initializes a new node for a linked list.
 *
 * @param data The data to bind to the new node in the list.
 * @return Returns a new linked list node
 */
Node *list_initialize(void *data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

/**
 * Adds a new item to the tail of a linked list
 *
 * @param head The head of a linked list
 * @param data The data to add to the tail of a linked list
 * @return Returns the new node tail node
 */
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

/**
 * Returns a specific node by zero based index in a linked list.
 *
 * @param self the head of the linked list
 * @param index the offset from the head of the node to return
 * @return Returns the node at the specified offset or NULL.
 */
Node *list_get(Node *self, int index) {
  if (!self || index < 0)
    return NULL;

  while (index > 0 && self) {
    self = self->next;
    index--;
  }
  return self;
}

/**
 * Returns the total number of nodes in a linked list.
 *
 * @param head The head of a linked list
 * @returns Returns the # of items in the list.
 */
int list_size(Node *head) {
  int i = 0;
  for (Node *tmp = head; tmp && tmp != NULL; tmp = tmp->next)
    i++;
  return i;
}

/**
 * Prints a visual representation of a linked list.
 *
 * @param self The head of the linked list
 * @param printer A callback function to invoke to print each item.
 */
void list_inspect(Node *self, Printer printer) {
  if (!self)
    return;

  printf("[");
  while (self) {
    printer(self->data);
    self = self->next;
  }
  printf("]\n");
}

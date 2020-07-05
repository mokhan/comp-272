#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * The equivalent of a constructor
 * to initialize a new node in a doubly linked list.
 *
 * @param data The data to initialize the head node with.
 * @return new Node bound to the data specified
 */
Node *initialize(int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

/**
 * Returns the tail of the list.
 *
 * @param head The head of the linked list
 * @return The tail of the linked list
 */
Node *tail(Node *head) {
  Node *tmp = head;
  while (tmp) {
    if (!tmp->next)
      break;
    tmp = tmp->next;
  }
  return tmp;
}

/**
 * Adds data to the tail of a doubly linked list.
 *
 * @param head The head of the doubly linked list
 * @param data The data to append to the list
 * @return Returns the new node.
 */
Node *add(Node *head, int data) {
  Node *t = tail(head);
  t->next = initialize(data);
  t->next->prev = t;
  return t->next;
}

/**
 * Returns a specific node in the list by index starting from 0.
 *
 * @param from The node to start scanning from.
 * @param index The zero based index of the node to retrieve.
 * @return The node at the specified index.
 */
Node *get(Node *from, int index) {
  if (!from || index < 0)
    return NULL;

  while (index > 0 && from) {
    from = from->next;
    index--;
  }
  return from;
}

/**
 * Returns the number of items in the linked list.
 *
 * @param head The head of the linked list
 * @return The number of items in the list.
 */
static int size(Node *head) {
  int i = 0;
  for (Node *tmp = head; tmp && tmp != NULL; tmp = tmp->next)
    i++;
  return i;
}

/**
 * Assigns the next pointer of a node.
 *
 * @param self The node struct to alter.
 * @param other The other node to point to.
 */
static void assign_next(Node *self, Node *other) {
  if (self)
    self->next = other;

  if (other)
    other->prev = self;
}

/**
 * Assigns the previous pointer of a node.
 *
 * @param self The node struct to alter.
 * @param other The other node to point to.
 */
static void assign_prev(Node *self, Node *other) {
  if (self)
    self->prev = other;

  if (other)
    other->next = self;
}

/**
 * Reverses a linked list.
 *
 * @param head The head of the linked list.
 * @return The new head of the linked list.
 */
Node *reverse(Node *head) {
  Node *tmp = NULL;
  Node *current = head;

  while (current != NULL) {
    tmp = current->prev;
    current->prev = current->next;
    current->next = tmp;
    current = current->prev;
  }
  return tmp ? tmp->prev : head;
}

/**
 * Generates a string representation of the Node usable for printing to stdout
 *
 * @param node The node to represent as a string
 * @return The string that represents the node
 */
char *to_s(Node *node) {
  const int buffer_size = 32;
  char *buffer = malloc(buffer_size);
  memset(buffer, buffer_size, '\0');

  if (node->prev && node->next)
    snprintf(buffer, buffer_size, "(%d<%d>%d) ", node->prev->data, node->data, node->next->data);
  else if (node->next)
    snprintf(buffer, buffer_size, "(nil<%d>%d) ", node->data, node->next->data);
  else
    snprintf(buffer, buffer_size, "(%d<%d>nil) ", node->prev->data, node->data);
  return buffer;
}

/**
 * Prints the previous, data and next pointers for a node
 *
 * @param node The node to print
 */
static void print(Node *node) {
  char *message = to_s(node);
  printf("%s", message);
  free(message);
}

/**
 * Iterates through each node in a linked list.
 *
 * @param self The node to start iterating from.
 * @param block The callback function to invoke on each node.
 */
void each(Node *self, Visitor block) {
  Node *tmp = self;

  while (tmp) {
    block(tmp);
    tmp = tmp->next;
  }
}

/**
 * Renders a visual output of a full linked list.
 *
 * @param node The head of the linked list
 */
void inspect(Node *node) {
  printf("[ ");
  each(node, &print);
  printf("]\n");
}

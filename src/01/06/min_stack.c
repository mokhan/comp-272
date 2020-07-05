#include "min_stack.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * The equivalent of a constructor for initialzing
 * a new Node in a linked list.
 *
 * @param data The data to bind to the node
 * @param next The next node to point to. NULL for a new head.
 * @return The new linked list Node.
 */
static Node *new (int data, Node *next) {
  Node *node = malloc(sizeof(Node));
  node->next = next;
  node->data = data;
  return node;
}

/**
 * The equivalent of a constructor for initialzing
 * a new min Stack.
 *
 * @return The new Stack
 */
Stack *initialize(void) {
  Stack *self = malloc(sizeof(Stack));
  self->head = NULL;
  self->min = NULL;
  self->size = 0;
  return self;
}

/**
 * Returns the number of items on the stack.
 *
 * @param self The stack to investigate.
 */
int size(Stack *self) { return self->size; }

/**
 * Pushes a new item on to a Stack
 *
 * @param self The stack to push the data on to
 * @param data The data to push on to the Stack
 */
void push(Stack *self, int data) {
  if (!self->min || (data < self->min->data))
    self->min = new (data, self->min);

  self->head = new (data, self->head);
  self->size++;
}

/**
 * Iterates through each item in a linked list.
 *
 * @param head The head of the linked list
 * @block The callback function to invoke on each item in the list.
 */
void each(Node *head, Visitor block) {
  Node *tmp = head;

  while (tmp) {
    (*block)(tmp);
    tmp = tmp->next;
  }
}

/**
 * Returns the minimum value in the Stack.
 *
 * @param self The stack to investigate
 */
int min(Stack *self) {
  if (self->min)
    return self->min->data;

  if (self->head) {
    int min = self->head->data;
    Node *tmp = self->head->next;

    while (tmp) {
      if (tmp->data < min)
        min = tmp->data;
      tmp = tmp->next;
    }
    return min;
  }

  return (int)NULL;
}

/**
 * Pops off the item from the top of the Stack.
 *
 * @param self The stack to pop an item off of.
 */
int pop(Stack *self) {
  if (!self->head)
    return (int)NULL;

  Node *current = self->head;
  int data = current->data;
  if (data == self->min->data)
    self->min = self->min->next;
  self->head = current->next;
  self->size--;
  current->next = NULL;
  free(current);
  return data;
}

/**
 * Prints a visual representation a Node in the linked list.
 *
 * @param node The node to print.
 */
void print_node(Node *node) { printf("[%d]", node->data); }

/**
 * A helper function to print out a visual representation of a Stack.
 *
 * @param stack the Stack to print out.
 */
void inspect(Stack *stack) {
  printf("\t");
  each(stack->head, &print_node);
  printf("\n");
}

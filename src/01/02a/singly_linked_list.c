#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * The equivalent of a constructor to initalize a linked list.
 *
 * @param data The initial data to seed the linked list
 * @return Returns a new Node
 */
Node *initialize(int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

/**
 * Add a node to the tail of the linked list
 *
 * @param head The head of the linked list
 * @param data The data to add to the linked list
 */
Node *add(Node *head, int data) {
  Node *tail;
  Node *tmp = head;

  while(tmp) {
    if (!tmp->next)
      break;
    tmp = tmp->next;
  }
  tail = tmp;
  tail->next = initialize(data);
  return tail->next;
}

/**
 * Gets a specific node by index starting from index 0.
 *
 * @param self The Node to start from
 * @param index The index of the node to return
 * @return The node at the specific index
 */
Node *get(Node *self, int index) {
  if (!self || index < 0) return NULL;

  while(index > 0 && self){
    self = self->next;
    index--;
  }
  return self;
}

/**
 * Counts the number of items in the linked list
 *
 * @param head The head of the linked list
 * @return The # of items in the linked list
 */
static int size(Node *head) {
  int i = 0;
  for (Node *tmp = head; tmp && tmp != NULL; tmp = tmp->next) i++;
  return i;
}

/**
 * Swaps nodes in a linked list that are in positions
 * x and y.
 *
 * @param head The head of the linked list
 * @param x The node in position x
 * @param y The node in position y
 */
void swap(Node **head, int x, int y) {
  int count = size(*head);

  if (x == y) return;
  if (x >= count) return;
  if (y >= count) return;

  Node *xp = get(*head, x - 1);
  Node *yp = get(*head, y - 1);
  Node *xc = get(*head, x);
  Node *yc = get(*head, y);

  if (x == 0)
    *head = yc;
  else
    xp->next = yc;

  if (y == 0)
    *head = xc;
  else
    yp->next = xc;

  Node *tmp = yc->next;
  yc->next = xc->next;
  xc->next = tmp;
}

/**
 * A helper method used to print a visual representation
 * of a linked list
 *
 * @param node The head of the linked list
 */
void inspect(Node *node) {
  if (!node) return;

  printf("*******\n");
  while (node) {
    printf("\t%d\n", node->data);
    node = node->next;
  }
  printf("*******\n");
}

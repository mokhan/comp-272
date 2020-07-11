#include "binary_tree.h"
#include <stdlib.h>

Node *initialize(int data) {
  Node *item = malloc(sizeof(Node));
  item->data = data;
  item->left = NULL;
  item->right = NULL;
  return item;
}

void preorder_next(Node *node, Visitor visitor) {
  if (!node)
    return;

  visitor(node);
  preorder_next(node->left, visitor);
  preorder_next(node->right, visitor);
}

void destroy(Node *head) {
  free(head);
}

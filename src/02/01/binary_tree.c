#include "binary_tree.h"
#include <stdlib.h>

Node *initialize(int data) {
  Node *item = malloc(sizeof(Node));
  item->data = data;
  item->left = NULL;
  item->right = NULL;
  return item;
}

void preorder_traversal(Node *node, Visitor visitor) {
  if (!node)
    return;

  visitor(node);
  preorder_traversal(node->left, visitor);
  preorder_traversal(node->right, visitor);
}

void destroy(Node *head) {
  free(head);
}

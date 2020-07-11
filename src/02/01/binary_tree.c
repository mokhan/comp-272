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

void inorder_traversal(Node *node, Visitor visitor) {
  if (!node)
    return;

  inorder_traversal(node->left, visitor);
  visitor(node);
  inorder_traversal(node->right, visitor);
}

void postorder_traversal(Node *node, Visitor visitor) {
  if (!node)
    return;

  postorder_traversal(node->left, visitor);
  postorder_traversal(node->right, visitor);
  visitor(node);
}

static void destructor(Node *node) {
  free(node);
}

void destroy(Node *head) {
  postorder_traversal(head, destructor);
}

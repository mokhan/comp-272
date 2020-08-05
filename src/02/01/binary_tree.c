#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

Node *initialize(int data) {
  Node *item = malloc(sizeof(Node));
  item->data = data;
  item->left = NULL;
  item->right = NULL;
  return item;
}

void traverse(Node *node, Visitor visitor, enum Traversal traversal) {
  if (!node)
    return;

  switch (traversal) {
  case PREORDER:
    visitor(node);
    traverse(node->left, visitor, traversal);
    traverse(node->right, visitor, traversal);
    break;
  case INORDER:
    traverse(node->left, visitor, traversal);
    visitor(node);
    traverse(node->right, visitor, traversal);
    break;
  case POSTORDER:
    traverse(node->left, visitor, traversal);
    traverse(node->right, visitor, traversal);
    visitor(node);
    break;
  default:
    visitor(node);
    break;
  }
}

static void destructor(Node *node) { free(node); }

void destroy(Node *head) { traverse(head, destructor, POSTORDER); }

void inspect(Node *node, int level) {
  if (!node)
    return;

  for (int i = 0; i < level; i++)
    printf("  ");
  printf("(%d)\n", node->data);
  inspect(node->left, level + 1);
  inspect(node->right, level + 1);
}

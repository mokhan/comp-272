#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Initialize a new node for a Binary Tree.
 *
 * @param data the data to assign to the root of the tree.
 * @return The root of the binary tree.
 */
Node *initialize(int data) {
  Node *item = malloc(sizeof(Node));
  item->data = data;
  item->left = NULL;
  item->right = NULL;
  return item;
}

/*
 * Traverses a binary tree using the traversal algorithm specified.
 * Time: O(n)
 * Space: O(1)
 *
 * @param node The root of the binary tree
 * @param vistior A callback function to invoke on each node during the tree
 * traversal
 * @param traversal Specifies what type of traversal to perform
 */
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

/**
 * Frees the memory allocated for a node in a tree
 *
 * @param node The node in the binary tree to free
 */
static void destructor(Node *node) { free(node); }

/**
 * Frees the memory associated with each node in a binary tree.
 *
 * @param root The root of the tree
 */
void destroy(Node *root) { traverse(root, destructor, POSTORDER); }

/**
 * A helper method to print out a visual representation of the tree
 *
 * @param node A node in a binary tree.
 * @param level The level in the tree that the node is at
 */
void inspect(Node *node, int level) {
  if (!node)
    return;

  for (int i = 0; i < level; i++)
    printf("  ");
  printf("(%d)\n", node->data);
  inspect(node->left, level + 1);
  inspect(node->right, level + 1);
}

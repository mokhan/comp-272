#include "btree.h"
#include <limits.h>
#include <stdio.h>

/**
 * A helper function used
 * to print a visual representation
 * of a Binary Tree
 */
static void inspect(BTree *tree, int level) {
  if (!tree)
    return;

  for (int i = 0; i < level; i++)
    printf("  ");

  printf("%2d\n", tree->data);
  inspect(tree->left, level + 1);
  inspect(tree->right, level + 1);
}

/**
 * A recursive function that can
 * be used to ensure that each node in
 * a Binary Tree satisfies the
 * Binary Search Tree property.
 *
 * @param tree A tree or subtree to verify
 * @param min the minimum value that each node must be greater than
 * @param max the maximum value that each node must be less than.
 * @return Returns tree when the tree is a binary search tree, otherwise false.
 *
 *
 */
static bool in_range(BTree *tree, int min, int max) {
  if (!tree)
    return true;

  int data = tree->data;
  if (data < min || data > max)
    return false;

  return in_range(tree->left, min, data) && in_range(tree->right, data, max);
}

/**
 * Initializes a binary tree.
 *
 * @param the data to assign to the root node in the tree.
 * @return the root of the tree.
 */
BTree *btree_init(int data) {
  BTree *tree = malloc(sizeof(BTree));
  tree->left = NULL;
  tree->right = NULL;
  tree->data = data;
  return tree;
}

/**
 * A function that determines if a binary tree
 * is a binary search tree or not.
 *
 * @param tree The root of the tree to inspect
 * @return Returns true when the tree is a binary search tree;
 */
bool btree_is_bst(BTree *tree) { return in_range(tree, INT_MIN, INT_MAX); }

/**
 * A helper function used to print a visual
 * representation of the binary tree.
 *
 * @param tree The tree or subtree to inspect
 */
void btree_inspect(BTree *tree) { inspect(tree, 0); }

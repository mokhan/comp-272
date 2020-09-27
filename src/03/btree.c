#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Print a visual representation of an binary tree.
 *
 * @param tree The subtree to print
 * @param level The level in the tree that this subtree is in
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
 * Initializes an instance of an binary tree.
 *
 * @param data The value to assign to the new node in the tree.
 * @return Returns the new binary tree node instance.
 */
BTree *btree_initialize(int data) {
  BTree *tree = malloc(sizeof(BTree));
  tree->left = NULL;
  tree->right = NULL;
  tree->data = data;
  return tree;
}

/**
 * Inserts a new value into a binary subtree.
 *
 * @param tree The subtree to attempt to insert a new value into.
 * @param data The data to insert into the tree.
 * @return Returns the new root of the subtree.
 */
BTree *btree_insert(BTree *tree, int data) {
  if (!tree)
    return btree_initialize(data);

  if (data <= tree->data)
    if (tree->left)
      btree_insert(tree->left, data);
    else
      tree->left = btree_initialize(data);
  else if (tree->right)
    btree_insert(tree->right, data);
  else
    tree->right = btree_initialize(data);

  return tree;
}

/**
 * Returns the height of a binary subtree.
 *
 * @param tree The subtree to interrogate.
 * @return The height of the subtree
 */
int btree_height(BTree *tree) {
  if (tree == NULL)
    return 0;

  int left = btree_height(tree->left);
  int right = btree_height(tree->right);

  return (left > right) ? left + 1 : right + 1;
}

/**
 * Prints a visual inspection of
 * a binary tree for debugging purposes to stdout.
 *
 * @param tree The tree to visualize
 */
void btree_inspect(BTree *tree) { inspect(tree, 0); }

int btree_leaves(BTree *tree) {
  if (tree == NULL)
    return 0;

  if (tree->left == NULL && tree->right == NULL)
    return 1;

  return btree_leaves(tree->left) + btree_leaves(tree->right);
}

/**
 * Generates a binary tree with a desired number of leaf
 * nodes.
 *
 * @param leaves The total number of leaf nodes to generate in the tree.
 * @return Returns a new binary tree.
 */
BTree *btree_generate(int leaves) {
  BTree *tree = NULL;

  while (btree_leaves(tree) < leaves)
    tree = btree_insert(tree, rand());
  return tree;
}

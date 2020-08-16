#include "btree.h"
#include <stdio.h>

/**
 * A helper function used to print a visual
 * representation of a binary tree.
 *
 * @param tree the tree or subtree to inspect
 * @param level the level of the subtree
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
 * Initializes the root of a binary tree
 *
 * @param data the data to assign to the root of the tree.
 * @return Returns the root of the tree.
 */
BTree *btree_init(int data) {
  BTree *tree = malloc(sizeof(BTree));
  tree->left = NULL;
  tree->right = NULL;
  tree->data = data;
  return tree;
}

/**
 * Inserts a new node into a binary tree.
 *
 * @param tree the tree to insert the new new into
 * @return Returns the root of the tree.
 */
BTree *btree_insert(BTree *tree, int data) {
  if (!tree)
    return btree_init(data);

  if (data <= tree->data)
    if (tree->left)
      btree_insert(tree->left, data);
    else
      tree->left = btree_init(data);
  else if (tree->right)
    btree_insert(tree->right, data);
  else
    tree->right = btree_init(data);

  return tree;
}

/**
 * A helper function used to print
 * a visual representation of a binary
 * tree.
 *
 * @param tree The root of the tree to inspect
 */
void btree_inspect(BTree *tree) { inspect(tree, 0); }

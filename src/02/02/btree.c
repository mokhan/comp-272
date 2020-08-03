#include "btree.h"
#include <limits.h>
#include <stdio.h>

static void inspect(BTree *tree, int level) {
  if (!tree)
    return;

  for (int i = 0; i < level; i++)
    printf("  ");

  printf("%2d\n", tree->data);
  inspect(tree->left, level + 1);
  inspect(tree->right, level + 1);
}

static bool in_range(BTree *tree, int min, int max) {
  if (!tree)
    return true;

  int data = tree->data;
  if (data < min || data > max)
    return false;

  return in_range(tree->left, min, data) && in_range(tree->right, data, max);
}

BTree *btree_init(int data) {
  BTree *tree = malloc(sizeof(BTree));
  tree->left = NULL;
  tree->right = NULL;
  tree->data = data;
  return tree;
}

bool btree_is_bst(BTree *tree) { return in_range(tree, INT_MIN, INT_MAX); }

void btree_inspect(BTree *tree) { inspect(tree, 0); }

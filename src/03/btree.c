#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

static void inspect(BTree *tree, int level) {
  if (!tree)
    return;

  for (int i = 0; i < level; i++)
    printf("  ");

  printf("%2d\n", tree->data);
  inspect(tree->left, level + 1);
  inspect(tree->right, level + 1);
}

BTree *btree_initialize(int data) {
  BTree *tree = malloc(sizeof(BTree));
  tree->left = NULL;
  tree->right = NULL;
  tree->data = data;
  return tree;
}

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

int btree_height(BTree *tree) {
  if (tree == NULL)
    return 0;

  int left = btree_height(tree->left);
  int right = btree_height(tree->right);

  return (left > right) ? left + 1 : right + 1;
}

void btree_inspect(BTree *tree) { inspect(tree, 0); }

int btree_leaves(BTree *tree) {
  if (tree == NULL)
    return 0;

  if (tree->left == NULL && tree->right == NULL)
    return 1;

  return btree_leaves(tree->left) + btree_leaves(tree->right);
}

BTree *btree_generate(int leaves) {
  BTree *tree = NULL;

  while (btree_leaves(tree) < leaves)
    tree = btree_insert(tree, rand());
  return tree;
}

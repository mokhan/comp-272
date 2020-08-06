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

BTree *btree_init(int data) {
  BTree *tree = malloc(sizeof(BTree));
  tree->left = NULL;
  tree->right = NULL;
  tree->data = data;
  return tree;
}

void btree_pre_order_number(BTree *tree) {
  //self
  //left
  //right
}
void btree_in_order_number(BTree *tree) {
  // left
  // self
  // right
}
void btree_post_order_number(BTree *tree) {
  // left
  // right
  // self
}

BTree *btree_insert(BTree *tree, int data) {
  if (!tree)
    return btree_init(data);

  if (data <= tree->data)
    if (tree->left)
      btree_insert(tree->left, data);
    else
      tree->left = btree_init(data);
  else
    if (tree->right)
      btree_insert(tree->right, data);
    else
      tree->right = btree_init(data);

  return tree;
}

void btree_inspect(BTree *tree) { inspect(tree, 0); }

#include "btree.h"

BTree *btree_init(int data) {
  BTree *tree = malloc(sizeof(BTree));
  tree->left = NULL;
  tree->right = NULL;
  tree->data = data;
  return tree;
}

BTree *btree_insert(BTree *tree, int data) {
  if (!tree)
    return btree_init(data);

  if (data <= tree->data) {
    tree->left = btree_init(data);
  } else {
    tree->right = btree_init(data);
  }

  return tree;
}

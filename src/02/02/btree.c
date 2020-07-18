#include "btree.h"

BTree *btree_init(int data) {
  BTree *tree = malloc(sizeof(BTree));
  tree->left = NULL;
  tree->right = NULL;
  tree->data = data;
  return tree;
}

bool btree_is_bst(BTree *tree) {
  if (tree) {
    return true;
  }
  return false;
}

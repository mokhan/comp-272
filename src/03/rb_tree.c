#include "rb_tree.h"
#include <stdlib.h>

RBTree *rb_tree_initialize(int value) {
  RBTree *tree = malloc(sizeof(RBTree));
  tree->colour = black;
  tree->left = NULL;
  tree->right = NULL;
  tree->value = value;
  return tree;
}

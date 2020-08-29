#include "rb_tree.h"
#include <stdlib.h>
#include <stdio.h>

RBTree *rb_tree_initialize(int value) {
  RBTree *tree = malloc(sizeof(RBTree));
  tree->colour = black;
  tree->left = NULL;
  tree->right = NULL;
  tree->value = value;
  return tree;
}

RBTree *rb_tree_insert(RBTree *tree, int value) {
  if (tree == NULL)
    return rb_tree_initialize(value);

  if (value < tree->value) {
    tree->left = rb_tree_insert(tree->left, value);
  } else if (value > tree->value) {
    tree->right = rb_tree_insert(tree->right, value);
  } else {
    printf("KABOOM");
  }
  return tree;
}

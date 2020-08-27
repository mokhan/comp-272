#include "avl_tree.h"
#include <stdlib.h>

AVLNode *avl_node_init(int value) {
  AVLNode *node = malloc(sizeof(AVLNode));
  node->left = NULL;
  node->right = NULL;
  node->value = value;
  return node;
}

AVLTree *avl_tree_init() {
  AVLTree *tree = malloc(sizeof(AVLTree));
  return tree;
}

int avl_tree_size(AVLTree *tree) {
  if (tree->root)
    return 1;
  else
    return 0;
}

void avl_tree_insert(AVLTree *tree, int value) {
  tree->root = avl_node_init(value);
}

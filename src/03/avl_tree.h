#include "rb_tree.h"

typedef struct node {
  struct node *left;
  struct node *right;
  int height;
  int value;
} AVLTree;

AVLTree *avl_tree_initialize(int value);
int avl_tree_size(AVLTree *tree);
AVLTree *avl_tree_insert(AVLTree *tree, int value);
AVLTree *avl_tree_delete(AVLTree *tree, int value);
void avl_tree_inspect(AVLTree *tree);
RBTree *avl_tree_to_rb_tree(AVLTree *tree);

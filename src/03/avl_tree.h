typedef struct node {
  struct node *left;
  struct node *right;
  int height;
  int value;
} AVLTree;

AVLTree *avl_tree_initialize(int value);
int avl_tree_size(AVLTree *tree);
AVLTree *avl_tree_insert(AVLTree *tree, int value);
void avl_tree_inspect(AVLTree *tree);

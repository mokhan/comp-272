typedef struct node {
  struct node *left;
  struct node *right;
  int value;
} AVLNode;

typedef struct {
  AVLNode *root;
} AVLTree;

AVLTree *avl_tree_init(void);
int avl_tree_size(AVLTree *tree);
void avl_tree_insert(AVLTree *tree, int value);

typedef struct node {
  struct node *left;
  struct node *right;
  int data;
} BTree;

BTree *btree_initialize(int data);
BTree *btree_insert(BTree *tree, int data);
int btree_height(BTree *tree);
void btree_inspect(BTree *tree);
BTree *btree_generate(int leaves);

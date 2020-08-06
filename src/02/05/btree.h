#include <stdlib.h>
#include <stdbool.h>

typedef struct btree_node {
  struct btree_node *left;
  struct btree_node *right;
  int *in_order;
  int *post_order;
  int *pre_order;
  int data;
} BTree;

BTree *btree_init(int data);
BTree *btree_insert(BTree *root, int data);
void btree_inspect(BTree *tree);

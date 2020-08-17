#include <stdlib.h>
#include <stdbool.h>

typedef struct btree_node {
  struct btree_node *left;
  struct btree_node *right;
  struct btree_node *parent;
  int data;
} BTree;

BTree *btree_initialize(BTree *parent, int data);
BTree *btree_insert(BTree *root, int data);
BTree *btree_rebalance(BTree *tree);
void btree_inspect(BTree *tree);
int btree_size(BTree *tree);

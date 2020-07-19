#include <stdlib.h>
#include <stdbool.h>

typedef struct btree_node {
  struct btree_node *left;
  struct btree_node *right;
  int data;
} BTree;

BTree *btree_init(int data);
bool btree_is_bst(BTree *tree);
void btree_inspect(BTree *tree);

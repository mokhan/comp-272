#include <stdlib.h>
#include <stdbool.h>

typedef struct btree_node {
  struct btree_node *left;
  struct btree_node *right;
  int data;
} BTree;

BTree *btree_init(int data);
BTree *btree_insert(BTree *root, int data);

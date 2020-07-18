#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  struct node *left;
  struct node *right;
  int data;
} BTree;

BTree *btree_init(int data);
bool btree_is_bst(BTree *tree);

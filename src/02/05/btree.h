#include <stdlib.h>
#include <stdbool.h>

typedef struct btree_node {
  struct btree_node *left;
  struct btree_node *right;
  int pre_order[32];
  int in_order[32];
  int post_order[32];
  int data;
} BTree;

BTree *btree_init(int data);
BTree *btree_insert(BTree *root, int data);
void btree_in_order_number(BTree *tree);
void btree_inspect(BTree *tree);
void btree_post_order_number(BTree *tree);
void btree_pre_order_number(BTree *tree);

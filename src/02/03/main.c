#include "btree.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("=== COMP-272 - Assignment 02 - Question 03 ===\n");
  printf("Tree 1: unbalanced tree\n");
  BTree *tree = btree_insert(NULL, 1);
  btree_insert(tree, 5);
  btree_insert(tree, 2);
  btree_insert(tree, 4);
  btree_insert(tree, 3);
  btree_inspect(tree);

  printf("Tree 2: balanced tree\n");
  tree = btree_insert(NULL, 3);
  btree_insert(tree, 2);
  btree_insert(tree, 4);
  btree_insert(tree, 1);
  btree_insert(tree, 5);
  btree_inspect(tree);

  printf("Bye\n");
  return 0;
}

#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("=== COMP-272 - Assignment 02 - Question 05 ===\n");
  BTree *tree = btree_insert(NULL, 10);
  btree_insert(tree, 5);
  btree_insert(tree, 15);
  btree_insert(tree, 7);
  btree_insert(tree, 12);
  btree_insert(tree, 18);
  btree_insert(tree, 3);
  btree_inspect(tree);

  btree_pre_order_number(tree);
  btree_in_order_number(tree);
  btree_post_order_number(tree);

  printf("Pre order traversal:\n");
  for (int i = 0; i < 32; i++)
    printf("%d ", tree->pre_order[i]);
  printf("\n");
  printf("\n");

  printf("In order traversal:\n");
  for (int i = 0; i < 32; i++)
    printf("%d ", tree->in_order[i]);
  printf("\n");
  printf("\n");

  printf("Post order traversal:\n");
  for (int i = 0; i < 32; i++)
    printf("%d ", tree->post_order[i]);
  printf("\n");
  printf("\n");

  printf("Bye\n");
  return 0;
}

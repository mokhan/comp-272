#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

void investigate(BTree *tree) {
  btree_inspect(tree);
  printf("Is a binary search tree? %c\n\n", btree_is_bst(tree) ? 'y' : 'n');
}

BTree *build_binary_search_tree() {
  BTree *tree = btree_init(10);
  tree->left = btree_init(-5);
  tree->left->left = btree_init(-10);
  tree->left->right = btree_init(5);

  tree->right = btree_init(25);
  tree->right->left = btree_init(23);
  tree->right->right = btree_init(36);
  return tree;
}

BTree *build_binary_tree() {
  BTree *tree = btree_init(10);
  tree->left = btree_init(0);
  tree->left->left = btree_init(-1);
  tree->left->right = btree_init(21);

  tree->right = btree_init(25);
  tree->right->left = btree_init(16);
  tree->right->right = btree_init(32);

  return tree;
}

int main(int argc, char *argv[]) {
  printf("=== COMP-272 - Assignment 02 - Question 02 ===\n");

  printf("Binary Search Tree\n");
  printf("---------\n");
  investigate(build_binary_search_tree());

  printf("Binary Tree\n");
  printf("---------\n");
  investigate(build_binary_tree());

  printf("Bye\n");
  return 0;
}

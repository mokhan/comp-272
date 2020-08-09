#include "btree.h"
#include "stack.h"
#include <stdio.h>

static void inspect(BTree *tree, int level) {
  if (!tree)
    return;

  for (int i = 0; i < level; i++)
    printf("  ");

  printf("%2d\n", tree->data);
  inspect(tree->left, level + 1);
  inspect(tree->right, level + 1);
}

BTree *btree_init(int data) {
  BTree *tree = malloc(sizeof(BTree));
  tree->left = NULL;
  tree->right = NULL;
  tree->data = data;
  return tree;
}

void btree_pre_order_number(BTree *root) {
  BTree *original = root;
  if (root == NULL) return;

  Stack *stack = stack_init();
  int i = 0;

  stack_push(stack, root);
  printf("[ ");
  while (stack_size(stack) > 0) {
    root = stack_pop(stack);
    original->pre_order[i++] = root->data;
    printf("%d ", root->data);

    if (root->right != NULL) {
      stack_push(stack, root->right);
    }
    if (root->left != NULL) {
      stack_push(stack, root->left);
    }
  }
  printf("]\n");
}

void btree_in_order_number(BTree *root) {
  BTree *original = root;
  if (root == NULL) return;

  Stack *stack = stack_init();
  int i = 0;

  while (true) {
    if (root) {
      stack_push(stack, root);
      root = root->left;
    }
    else {
      if (stack_size(stack) == 0)
        break;

      root = stack_pop(stack);
      original->in_order[i++] = root->data;
      root = root->right;
    }
  }
}

void btree_post_order_number(BTree *tree) {
  // left
  // right
  // self
}

BTree *btree_insert(BTree *tree, int data) {
  if (!tree)
    return btree_init(data);

  if (data <= tree->data)
    if (tree->left)
      btree_insert(tree->left, data);
    else
      tree->left = btree_init(data);
  else
    if (tree->right)
      btree_insert(tree->right, data);
    else
      tree->right = btree_init(data);

  return tree;
}

void btree_inspect(BTree *tree) { inspect(tree, 0); }

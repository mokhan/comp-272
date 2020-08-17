#include "btree.h"
#include "list.h"
#include "stack.h"
#include <stdio.h>

/**
 * A helper function used to print a visual
 * representation of a binary tree.
 *
 * @param tree the tree or subtree to inspect
 * @param level the level of the subtree
 */
static void inspect(BTree *tree, int level) {
  if (!tree)
    return;

  for (int i = 0; i < level; i++)
    printf("  ");

  printf("%2d\n", tree->data);
  inspect(tree->left, level + 1);
  inspect(tree->right, level + 1);
}

/**
 * Initializes an new subtree in a binary tree
 *
 * @param parent the parent of the new btree node
 * @param data the data to assign to the root of the tree.
 * @return Returns the new subtree
 */
BTree *btree_initialize(BTree *parent, int data) {
  BTree *tree = malloc(sizeof(BTree));
  tree->parent = parent;
  tree->left = NULL;
  tree->right = NULL;
  tree->data = data;
  return tree;
}

List *btree_to_list(BTree *tree)
{
  if (tree == NULL)
    return NULL;

  List *list = NULL;
  Stack *stack = stack_init();
  BTree *tmp = tree;

  while (true) {
    if (tmp) {
      stack_push(stack, tmp);
      tmp = tmp->left;
    } else if (stack_size(stack) == 0) {
      break;
    } else {
      tmp = stack_pop(stack);
      if (list)
        list_add(list, tmp->data);
      else
        list = list_initialize(tree->data);
      tmp = tmp->right;
    }
  }

  return list;
}

int btree_size(BTree *tree) {
  List *list = btree_to_list(tree);
  return list ? list_size(list) : 0;
}

BTree *btree_rebalance(BTree *tree)
{
  if (!tree->parent)
    return tree;

  int size = btree_size(tree);
  int parent_size = btree_size(tree->parent);
  /*float ratio = size / parent_size;*/
  float ratio = 0.0;
  printf("%d / %d = %f\n", size, parent_size, ratio);

  return tree;
}

/**
 * Inserts a new node into a binary tree.
 *
 * @param tree the tree to insert the new new into
 * @return Returns the root of the tree.
 */
BTree *btree_insert(BTree *tree, int data) {
  if (!tree)
    return btree_initialize(NULL, data);

  if (data <= tree->data)
    if (tree->left)
      btree_insert(tree->left, data);
    else
      tree->left = btree_initialize(tree, data);
  else if (tree->right)
    btree_insert(tree->right, data);
  else
    tree->right = btree_initialize(tree, data);

  /*return btree_rebalance(tree);*/
  return tree;
}

/**
 * A helper function used to print
 * a visual representation of a binary
 * tree.
 *
 * @param tree The root of the tree to inspect
 */
void btree_inspect(BTree *tree) { inspect(tree, 0); }

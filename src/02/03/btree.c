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

/**
 * Converts a binary tree into a linked list
 * using an in order traversal.
 *
 * @param tree The binary tree to convert
 * @return Returns the head of a linked list.
 */
List *btree_to_list(BTree *tree) {
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
        list_add(list, tmp);
      else
        list = list_initialize(tree);
      tmp = tmp->right;
    }
  }

  return list;
}

/**
 * Calculates the size of a binary tree
 *
 * @param tree the tree to inspect
 * @return Returns the # of nodes in the binary tree.
 */
int btree_size(BTree *tree) {
  List *list = btree_to_list(tree);
  return list ? list_size(list) : 0;
}

/**
 * Determines if a subtree in a binary tree
 * can be used as a scapegoat to rebalance
 * the tree.
 *
 * @param tree the subtree to investigate
 * @return Returns true then subtree can be used as a scapegoat.
 */
bool btree_is_scapegoat(BTree *tree) {
  int size = btree_size(tree);
  int parent_size = btree_size(tree->parent);

  return ((size * 3) > (parent_size * 2));
}

/**
 * Rebuilds a subtree by converting it
 * to a list then rebuilding a binary tree.
 *
 * @param tree The tree to rebuild
 * @return Returns the new binary tree.
 */
BTree *btree_rebuild(BTree *tree) {
  List *list = btree_to_list(tree->parent);
  int mid = (list_size(list) / 2) - 1;
  List *new_root = list_get(list, mid);
  int data = ((BTree *)new_root->data)->data;
  BTree *new_broot = btree_initialize(NULL, data);

  for (int i = 0; i < list_size(list); i++) {
    if (i == mid)
      continue;

    int data = ((BTree *)list_get(list, i)->data)->data;
    btree_insert(new_broot, data);
  }
  return new_broot;
}

/**
 * Rebalances a binary tree starting from
 * the bottom up.
 *
 * @param tree the subtree to rebalance
 * @return Returns the new root of the binary tree.
 */
BTree *btree_rebalance(BTree *tree) {
  if (!tree->parent)
    return tree;

  if (btree_is_scapegoat(tree))
    return btree_rebuild(tree);

  return btree_rebalance(tree->parent);
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
      return btree_insert(tree->left, data);
    else {
      tree->left = btree_initialize(tree, data);
      return btree_rebalance(tree->left);
    }
  else if (tree->right)
    return btree_insert(tree->right, data);
  else {
    tree->right = btree_initialize(tree, data);
    return btree_rebalance(tree->right);
  }

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

#include "btree.h"
#include "stack.h"
#include <stdio.h>

/**
 * Prints a visual representation of a binary tree
 *
 * @param tree The tree or subtree to print
 * @param level The level in the tree that the subtree belongs to
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
 * Initializes a new instance of a binary tree.
 *
 * @param data The data to bind to the root of the new subtree.
 * @return Returns the new subtree.
 */
BTree *btree_init(int data) {
  BTree *tree = malloc(sizeof(BTree));
  tree->left = NULL;
  tree->right = NULL;
  tree->data = data;
  return tree;
}

/**
 * Performs and caches the result of a pre order traversal
 * on a binary tree. Cached results are stored in the root of
 * the tree and not on each node of the tree.
 *
 * @param tree The subtree to perform the traversal on
 */
void btree_pre_order_number(BTree *tree) {
  BTree *original = tree;
  if (tree == NULL)
    return;

  Stack *stack = stack_init();
  int i = 0;

  stack_push(stack, tree);
  while (stack_size(stack) > 0) {
    tree = stack_pop(stack);
    original->pre_order[i++] = tree->data;

    if (tree->right != NULL)
      stack_push(stack, tree->right);
    if (tree->left != NULL)
      stack_push(stack, tree->left);
  }
}

/**
 * Performs and caches the result of an in order traversal
 * on a binary tree. Cached results are stored in the root of
 * the tree and not on each node of the tree.
 *
 * @param root The subtree to perform the traversal on
 */
void btree_in_order_number(BTree *root) {
  BTree *original = root;
  if (root == NULL)
    return;

  Stack *stack = stack_init();
  int i = 0;

  while (true) {
    if (root) {
      stack_push(stack, root);
      root = root->left;
    } else {
      if (stack_size(stack) == 0)
        break;

      root = stack_pop(stack);
      original->in_order[i++] = root->data;
      root = root->right;
    }
  }
}

/**
 * Performs and caches the result of an post order traversal
 * on a binary tree. Cached results are stored in the root of
 * the tree and not on each node of the tree.
 *
 * @param root The subtree to perform the traversal on
 */
void btree_post_order_number(BTree *root) {
  BTree *original = root;
  if (root == NULL)
    return;

  Stack *s1 = stack_init();
  Stack *s2 = stack_init();

  stack_push(s1, root);

  while (stack_size(s1) > 0) {
    root = stack_pop(s1);
    stack_push(s2, root);

    if (root->left)
      stack_push(s1, root->left);
    if (root->right)
      stack_push(s1, root->right);
  }

  int i = 0;
  while (stack_size(s2) > 0) {
    root = stack_pop(s2);
    original->post_order[i++] = root->data;
  }
}

/**
 * Insert a new items into a binary tree.
 *
 * @param tree The tree to insert the data into.
 * @param data The data to insert into the tree.
 * @return Returns the new root of the tree.
 */
BTree *btree_insert(BTree *tree, int data) {
  if (!tree)
    return btree_init(data);

  if (data <= tree->data)
    if (tree->left)
      btree_insert(tree->left, data);
    else
      tree->left = btree_init(data);
  else if (tree->right)
    btree_insert(tree->right, data);
  else
    tree->right = btree_init(data);

  return tree;
}

/**
 * Prints a visual representation of a binary tree.
 *
 * @param tree The subtree to inspect.
 */
void btree_inspect(BTree *tree) { inspect(tree, 0); }

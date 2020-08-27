#include "avl_tree.h"
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
  return (a > b) ? a : b;
}

int height_of(AVLTree *node) {
  return node == NULL ? 0 : node->height;
}

AVLTree *smallest(AVLTree *node) {
  AVLTree *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

AVLTree *rotate_right(AVLTree *y) {
  AVLTree *x = y->left;
  AVLTree *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height_of(y->left), height_of(y->right)) + 1;
  x->height = max(height_of(x->left), height_of(x->right)) + 1;

  return x;
}

AVLTree *rotate_left(AVLTree *x) {
  AVLTree *y = x->right;
  AVLTree *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height_of(x->left), height_of(x->right)) + 1;
  y->height = max(height_of(y->left), height_of(y->right)) + 1;

  return y;
}

int balance_of(AVLTree *node) {
  return (node == NULL) ? 0 : height_of(node->left) - height_of(node->right);
}

AVLTree *avl_tree_initialize(int value) {
  AVLTree *node = malloc(sizeof(AVLTree));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}

int avl_tree_size(AVLTree *tree) {
  int total = 0;
  if (tree == NULL)
    return total;
  if (tree->left)
    total += avl_tree_size(tree->left);
  if (tree->right)
    total += avl_tree_size(tree->right);
  return total + 1;
}

AVLTree *avl_tree_insert(AVLTree *tree, int value) {
  if (tree == NULL)
    return avl_tree_initialize(value);

  if (value < tree->value)
    tree->left = avl_tree_insert(tree->left, value);
  else if (value > tree->value)
    tree->right = avl_tree_insert(tree->right, value);
  else
    return tree;

  tree->height = 1 + max(height_of(tree->left), height_of(tree->right));

  int balance = balance_of(tree);
  if (balance > 1 && value < tree->left->value)
    return rotate_right(tree);

  if (balance < -1 && value > tree->right->value)
    return rotate_left(tree);

  if (balance > 1 && value > tree->left->value) {
    tree->left = rotate_left(tree->left);
    return rotate_right(tree);
  }

  if (balance < -1 && value < tree->right->value) {
    tree->right = rotate_right(tree->right);
    return rotate_left(tree);
  }

  return tree;
}

AVLTree *node_delete(AVLTree *root, int value) {
  if (root == NULL)
    return root;

  if (value < root->value)
    root->left = node_delete(root->left, value);
  else if (value > root->value)
    root->right = node_delete(root->right, value);
  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      AVLTree *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else {
        *root = *temp;
      }
      free(temp);
    } else {
      AVLTree *temp = smallest(root->right);
      root->value = temp->value;
      root->right = node_delete(root->right, temp->value);
    }
  }

  if (root == NULL)
    return root;

  root->height = 1 + max(height_of(root->left), height_of(root->right));

  int balance = balance_of(root);
  if (balance > 1 && balance_of(root->left) >= 0)
    return rotate_right(root);

  if (balance > 1 && balance_of(root->left) < 0) {
    root->left = rotate_left(root->left);
    return rotate_right(root);
  }

  if (balance < -1 && balance_of(root->right) <= 0)
    return rotate_left(root);

  if (balance < -1 && balance_of(root->right) > 0) {
    root->right = rotate_right(root->right);
    return rotate_left(root);
  }

  return root;
}

void print_tree(AVLTree *tree, int level) {
  for (int i = 0; i < level; i++)
    printf(" ");

  if (tree) {
    printf("(%d)\n", tree->value);

    if (!tree->left && !tree->right)
      return;
    print_tree(tree->left, level + 1);
    print_tree(tree->right, level + 1);
  }
  else {
    printf("( )\n");
  }
}

void avl_tree_inspect(AVLTree *tree) {
  print_tree(tree, 0);
}

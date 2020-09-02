#include "avl_tree.h"
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
  return (a > b) ? a : b;
}

int height_of(AVLTree *tree) {
  return tree == NULL ? 0 : tree->height;
}

AVLTree *smallest(AVLTree *tree) {
  AVLTree *current = tree;

  while (current->left != NULL)
    current = current->left;

  return current;
}

AVLTree *rotate_right(AVLTree *y) {
  AVLTree *x = y->left;
  AVLTree *t = x->right;

  x->right = y;
  y->left = t;

  y->height = max(height_of(y->left), height_of(y->right)) + 1;
  x->height = max(height_of(x->left), height_of(x->right)) + 1;

  return x;
}

AVLTree *rotate_left(AVLTree *x) {
  AVLTree *y = x->right;
  AVLTree *t = y->left;

  y->left = x;
  x->right = t;

  x->height = max(height_of(x->left), height_of(x->right)) + 1;
  y->height = max(height_of(y->left), height_of(y->right)) + 1;

  return y;
}

int balance_of(AVLTree *tree) {
  return (tree == NULL) ? 0 : height_of(tree->left) - height_of(tree->right);
}

AVLTree *avl_tree_initialize(int value) {
  AVLTree *tree = malloc(sizeof(AVLTree));
  tree->value = value;
  tree->left = NULL;
  tree->right = NULL;
  tree->height = 1;
  return tree;
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

int compare(int a, int b)
{
  return (a < b) ? -1 : ((a > b) ? 1 : 0);
}

AVLTree *avl_tree_insert(AVLTree *tree, int value) {
  if (tree == NULL)
    return avl_tree_initialize(value);

  switch(compare(value, tree->value)) {
    case -1:
      tree->left = avl_tree_insert(tree->left, value);
      break;
    case 1:
      tree->right = avl_tree_insert(tree->right, value);
      break;
    default:
      return tree;
  }

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

AVLTree *avl_tree_delete(AVLTree *tree, int value) {
  if (tree == NULL)
    return tree;

  switch(compare(value, tree->value)) {
    case -1:
      tree->left = avl_tree_delete(tree->left, value);
      break;
    case 1:
      tree->right = avl_tree_delete(tree->right, value);
      break;
    default:
      if (tree->left && tree->right) {
        AVLTree *min = smallest(tree->right);
        tree->value = min->value;
        tree->right = avl_tree_delete(tree->right, min->value);
      } else {
        AVLTree *tmp = tree->left ? tree->left : tree->right;

        if (tmp) {
          *tree = *tmp;
          free(tmp);
        } else {
          free(tree);
          return NULL;
        }
      }
      break;
  }

  tree->height = 1 + max(height_of(tree->left), height_of(tree->right));

  int balance = balance_of(tree);
  if (balance > 1 && balance_of(tree->left) >= 0)
    return rotate_right(tree);

  if (balance > 1 && balance_of(tree->left) < 0) {
    tree->left = rotate_left(tree->left);
    return rotate_right(tree);
  }

  if (balance < -1 && balance_of(tree->right) <= 0)
    return rotate_left(tree);

  if (balance < -1 && balance_of(tree->right) > 0) {
    tree->right = rotate_right(tree->right);
    return rotate_left(tree);
  }

  return tree;
}

static void print_tree(AVLTree *tree, int level) {
  for (int i = 0; i < level; i++)
    printf(" ");

  if (tree) {
    printf("(%d:%d)\n", tree->value, tree->height);

    if (!tree->left && !tree->right)
      return;
    print_tree(tree->left, level + 1);
    print_tree(tree->right, level + 1);
  }
  else {
    printf("( )\n");
  }
}

static bool is_even(int value) {
  return value % 2 == 0;
}

static bool is_odd(int value) {
  return !is_even(value);
}

RBTree *_avl_tree_to_rb_tree(AVLTree *tree, AVLTree *parent) {
  if (!tree)
    return NULL;

  enum Colour colour = (parent && is_even(parent->height) && is_odd(tree->height)) ? red : black;
  RBTree *rb_tree = rb_tree_initialize_with(tree->value, colour);
  rb_tree->left = _avl_tree_to_rb_tree(tree->left, tree);
  rb_tree->right = _avl_tree_to_rb_tree(tree->right, tree);
  return rb_tree;
}

RBTree *avl_tree_to_rb_tree(AVLTree *tree) {
  if (!tree)
    return NULL;

  return _avl_tree_to_rb_tree(tree, NULL);
}

void avl_tree_inspect(AVLTree *tree) {
  print_tree(tree, 0);
}

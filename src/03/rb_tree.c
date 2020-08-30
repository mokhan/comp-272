#include "rb_tree.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Implementation derived from:
 * * https://en.wikipedia.org/wiki/Red%E2%80%93black_tree#Insertion
 */

RBTree *parent_of(RBTree *node) {
  return node ? node->parent : NULL;
}

RBTree *root_of(RBTree *node) {
  RBTree *current = node;
  RBTree *next = parent_of(current);

  while (next) {
    current = next;
    next = parent_of(current);
  }
  return current;
}

RBTree *grand_parent_of(RBTree *node) {
  return parent_of(parent_of(node));
}

RBTree *sibling_of(RBTree *node) {
  RBTree *parent = parent_of(node);

  if (!parent)
    return NULL;

  return node == parent->left ? parent->right : parent->left;
}

RBTree *pibling_of(RBTree *node) {
  return sibling_of(parent_of(node));
}

static void rb_rotate_left(RBTree *tree) {
  RBTree *tmp = tree->right;
  RBTree *parent = parent_of(tree);

  tree->right = tmp->left;
  tmp->left = tree;
  tree->parent = tmp;

  if (tree->right)
    tree->right->parent = tree;

  if (parent) {
    if (tree == parent->left)
      parent->left = tmp;
    else if (tree == parent->right)
      parent->right = tmp;
  }
  tmp->parent = parent;
}

static void rb_rotate_right(RBTree *tree) {
  RBTree *tmp = tree->left;
  RBTree *parent = parent_of(tree);

  tree->left = tmp->right;
  tmp->right = tree;
  tree->parent = tmp;

  if (tree->left)
    tree->left->parent = tree;

  if (parent) {
    if (tree == parent->left)
      parent->left = tmp;
    else if (tree == parent->right)
      parent->right = tmp;
  }
  tmp->parent = parent;
}

static void repair_from(RBTree *tree) {
  RBTree *parent = parent_of(tree);
  RBTree *pibling = pibling_of(tree);

  if (parent == NULL || parent->colour == black)
    return;

  if (pibling && pibling->colour == red) {
    parent->colour = black;
    pibling->colour = black;
    grand_parent_of(tree)->colour = red;
    repair_from(grand_parent_of(tree));
  } else {
    RBTree *grand_parent = grand_parent_of(tree);

    if (tree == parent->right && parent == grand_parent->left) {
      rb_rotate_left(parent);
    } else if (tree == parent->left && parent == grand_parent->right) {
      rb_rotate_right(parent);
      tree = tree->right;
    }

    parent = parent_of(tree);
    grand_parent = grand_parent_of(tree);

    if (tree == parent->left)
      rb_rotate_right(grand_parent);
    else
      rb_rotate_left(grand_parent);
    parent->colour = black;
    grand_parent->colour = red;
  }
}

static int compare(int a, int b) {
  return a == b ? 0 : a < b ? -1 : 1;
}

static void insert(RBTree *root, RBTree *node) {
  if (!root)
    return;

  if (compare(node->value, root->value) < 0) {
    if (root->left)
      insert(root->left, node);
    else {
      root->left = node;
      node->parent = root;
    }
  } else {
    if (root->right)
      insert(root->right, node);
    else {
      root->right = node;
      node->parent = root;
    }
  }
}

static void print_tree(RBTree *tree, int level) {
  for (int i = 0; i < level; i++)
    printf(" ");

  if (tree) {
    printf("(%d:%c)\n", tree->value, tree->colour == red ? 'R' : 'B');

    if (!tree->left && !tree->right)
      return;
    print_tree(tree->left, level + 1);
    print_tree(tree->right, level + 1);
  }
  else {
    printf("( )\n");
  }
}

RBTree *rb_tree_initialize_with(int value, enum Colour colour) {
  RBTree *tree = malloc(sizeof(RBTree));
  tree->colour = colour;
  tree->left = NULL;
  tree->parent = NULL;
  tree->right = NULL;
  tree->value = value;
  return tree;
}

RBTree *rb_tree_initialize(int value) {
  return rb_tree_initialize_with(value, black);
}

RBTree *rb_tree_insert(RBTree *tree, int value) {
  if (tree == NULL)
    return rb_tree_initialize(value);

  RBTree *node = rb_tree_initialize_with(value, red);
  insert(tree, node);
  repair_from(node);
  return root_of(node);
}

void rb_tree_inspect(RBTree *tree) {
  print_tree(tree, 0);
}

#include "rb_tree.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Implementation derived from:
 * * https://en.wikipedia.org/wiki/Red%E2%80%93black_tree#Insertion
 */

/**
 * Returns the larger integer between the two provided as arguments.
 *
 * @param a An integer value to compare
 * @param b Another integer value to compare
 * @return Returns the larger value
 */
static int max(int a, int b) { return a == b ? a : (a > b ? a : b); }

/**
 * Number of black nodes to leaf.
 *
 * @param tree The node to traverse down to a leaf.
 * @return the # of black nodes from the given node to a leaf.
 */
static int depth(RBTree *tree) {
  int total = 1;

  while (tree) {
    if (tree->colour == black)
      total += 1;
    tree = tree->left;
  }
  return total;
}

/**
 * Determines if a provided subtree is the root.
 *
 * @param node The subtree to investigate
 * @param Returns tree when the node is the root otherwise false.
 */
static bool is_root(RBTree *node) { return node->parent == NULL; }

/**
 * Returns the parent node of a node.
 *
 * @param node The node to investigate.
 * @return The parent of the node or NULL.
 */
static RBTree *parent_of(RBTree *node) { return node ? node->parent : NULL; }

/**
 * Returns the root of a subtree
 *
 * @param node The subtree to investigate
 * @return Returns the root of the subtree
 */
static RBTree *root_of(RBTree *node) {
  RBTree *current = node;
  RBTree *next = parent_of(current);

  while (next) {
    current = next;
    next = parent_of(current);
  }
  return current;
}

/**
 * Returns the grand parent node of a node.
 *
 * @param node The node to investigate.
 * @return The grand parent of the node or NULL.
 */
static RBTree *grand_parent_of(RBTree *node) {
  return parent_of(parent_of(node));
}

/**
 * Returns a sibling node of a given node.
 *
 * @param node The node to investigate.
 * @return The sibling of the node or NULL.
 */
static RBTree *sibling_of(RBTree *node) {
  RBTree *parent = parent_of(node);

  if (!parent)
    return NULL;

  return node == parent->left ? parent->right : parent->left;
}

/**
 * Returns a pibling (aunt/uncle) node of a given node.
 *
 * @param node The node to investigate.
 * @return The pibling of the node or NULL.
 */
static RBTree *pibling_of(RBTree *node) { return sibling_of(parent_of(node)); }

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

/**
 * Performs a right rotation on a subtree
 *
 * @param tree The subtree to perform the rotation on
 */
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

/**
 * Performs any repairs necessary on a subtree
 *
 * @param tree The subtree to perform a repair on
 */
static void repair_from(RBTree *tree) {
  RBTree *parent = parent_of(tree);
  RBTree *pibling = pibling_of(tree);

  if (parent == NULL || parent->colour == black) {
    return;
  }

  if (pibling && pibling->colour == red) {
    parent->colour = black;
    pibling->colour = black;
    RBTree *grand_parent = grand_parent_of(tree);
    if (grand_parent->parent)
      grand_parent->colour = red;
    repair_from(grand_parent_of(tree));
  } else {
    RBTree *grand_parent = grand_parent_of(tree);

    if (!grand_parent)
      return;
    if (tree == parent->right && parent == grand_parent->left) {
      rb_rotate_left(parent);
    } else if (tree == parent->left && parent == grand_parent->right) {
      rb_rotate_right(parent);
      tree = tree->right;
    }

    parent = parent_of(tree);
    grand_parent = grand_parent_of(tree);

    if (tree == parent->left) {
      rb_rotate_right(grand_parent);
    } else {
      rb_rotate_left(grand_parent);
    }
    parent->colour = black;
    if (grand_parent->parent)
      grand_parent->colour = red;
  }
}

/**
 * Compares two integers and returns -1, 0, 1.
 * If a is equal to b then 0 is returned.
 * If a is greater than b then 1 is returned.
 * If a is less than b then -1 is returned.
 *
 * @param a An integer
 * @param b Another integer
 * @return Returns 0, 1, or -1.
 */
static int compare(int a, int b) { return a == b ? 0 : a < b ? -1 : 1; }

/**
 * Inserts a new node into a subtree.
 *
 * @param tree The subtree to attempt to insert a new value into.
 * @param node The new node to insert.
 */
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

/**
 * Print a visual representation of a tree.
 *
 * @param tree The subtree to print
 * @param level The level in the tree that this subtree is in
 */
static void print_tree(RBTree *tree, int level) {
  for (int i = 0; i < level; i++)
    printf(" ");

  if (tree) {
    printf("(%d%c H:%d)\n", tree->value, tree->colour == red ? 'R' : 'B',
           rb_tree_height(tree));

    if (!tree->left && !tree->right)
      return;
    print_tree(tree->left, level + 1);
    print_tree(tree->right, level + 1);
  } else {
    printf("( )\n");
  }
}

/**
 * Initializes an instance of a tree.
 *
 * @param value The value to assign to the new node in the tree.
 * @param color The colour to assign to the new node in the tree.
 * @return Returns the new tree node instance.
 */
RBTree *rb_tree_initialize_with(int value, enum Colour colour) {
  RBTree *tree = malloc(sizeof(RBTree));
  tree->colour = colour;
  tree->left = NULL;
  tree->parent = NULL;
  tree->right = NULL;
  tree->value = value;
  return tree;
}

/**
 * Initializes an instance of a tree with a default colour of black.
 *
 * @param value The value to assign to the new node in the tree.
 * @return Returns the new tree node instance.
 */
RBTree *rb_tree_initialize(int value) {
  return rb_tree_initialize_with(value, black);
}

/**
 * Inserts a new value into a subtree.
 *
 * @param tree The subtree to attempt to insert a new value into.
 * @param value The value to insert.
 * @return Returns the new root of the subtree.
 */
RBTree *rb_tree_insert(RBTree *tree, int value) {
  if (tree == NULL)
    return rb_tree_initialize(value);

  RBTree *node = rb_tree_initialize_with(value, red);
  insert(tree, node);
  repair_from(node);
  return root_of(node);
}

/**
 * Prints a visual inspection of
 * a tree for debugging purposes to stdout.
 *
 * @param tree The tree to visualize
 */
void rb_tree_inspect(RBTree *tree) { print_tree(tree, 0); }

int rb_tree_size(RBTree *tree) {
  int total = 0;
  if (tree == NULL)
    return total;
  if (tree->left)
    total += rb_tree_size(tree->left);
  if (tree->right)
    total += rb_tree_size(tree->right);
  return total + 1;
}

/**
 * Determines if two trees are equal by verifying
 * that each descendant node in each subtree have
 * the same value and colour.
 *
 * @param tree A tree to compare
 * @param other_tree Another tree to compare
 * @return Returns true when both subtrees are equal otherwise false
 */
bool rb_equals(RBTree *tree, RBTree *other_tree) {
  if (!tree || !other_tree)
    return tree == other_tree;

  if (tree->parent && !other_tree->parent)
    return false;

  if (!tree->parent && other_tree->parent)
    return false;

  if (tree->parent && tree->parent->value != other_tree->parent->value)
    return false;

  return tree->value == other_tree->value &&
         tree->colour == other_tree->colour &&
         rb_equals(tree->left, other_tree->left) &&
         rb_equals(tree->right, other_tree->right);
}

/**
 * Determines if a tree matches the properties
 * necessary to claim to be a valid Red Black tree.
 *
 * 1. root must be black
 * 2. there are the same # of black nodes on every root to the leaf path.
 * 3. No two red nodes are adjacent.
 *
 * @param tree The tree to investigate
 * @return Returns true if the tree meets the criteria otherwise false.
 */
bool rb_tree_is_valid(RBTree *tree) {
  if (tree == NULL)
    return true;

  if (is_root(tree) && tree->colour == red)
    return false;

  if (tree->colour == red && tree->parent->colour == red)
    return false;

  if (depth(tree->left) != depth(tree->right))
    return false;

  return rb_tree_is_valid(tree->left) && rb_tree_is_valid(tree->right);
}

/**
 * Returns the height of a subtree.
 *
 * @param tree The subtree to investigate
 * @return Returns the height of the subtree
 */
int rb_tree_height(RBTree *tree) {
  if (!tree)
    return 1;

  return 1 + max(rb_tree_height(tree->left), rb_tree_height(tree->right));
}

/**
 * Searches for a node in a subtree with a particular value.
 *
 * @param t The subtree to search.
 * @param value The value to search for
 * @returns Returns the node containing the value otherwise NULL
 */
RBTree *rb_tree_find(RBTree *t, int value) {
  if (!t)
    return NULL;

  int x = compare(value, t->value);
  return x == 0 ? t : rb_tree_find(x < 0 ? t->left : t->right, value);
}

#include <stdbool.h>

enum Colour {
  black = 0x01,
  red = 0x00,
};

typedef struct rb_node {
  struct rb_node *left;
  struct rb_node *parent;
  struct rb_node *right;
  enum Colour colour;
  int value;
} RBTree;

RBTree *rb_tree_initialize(int value);
RBTree *rb_tree_insert(RBTree *tree, int value);
void rb_tree_inspect(RBTree *tree);
bool rb_equals(RBTree *tree, RBTree *other_tree);

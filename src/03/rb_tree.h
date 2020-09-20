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
RBTree *rb_tree_initialize_with(int value, enum Colour colour);
RBTree *rb_tree_insert(RBTree *tree, int value);
bool rb_equals(RBTree *tree, RBTree *other_tree);
bool rb_tree_is_valid(RBTree *tree);
int rb_tree_size(RBTree *tree);
void rb_tree_inspect(RBTree *tree);
int rb_tree_height(RBTree *tree);

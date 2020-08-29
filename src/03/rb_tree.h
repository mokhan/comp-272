enum Colour {
  black = 0x01,
  red = 0x00,
};

typedef struct rb_node {
  struct rb_node *left;
  struct rb_node *right;
  enum Colour colour;
  int value;
} RBTree;

RBTree *rb_tree_initialize(int value);
RBTree *rb_tree_insert(RBTree *tree, int value);

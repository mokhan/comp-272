enum colour {
  black = 0x01,
  red = 0x00,
};

typedef struct rb_node {
  struct rb_node *left;
  struct rb_node *right;
  enum colour colour;
  int value;
} RBTree;

RBTree *rb_tree_initialize(int value);

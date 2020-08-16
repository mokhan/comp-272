/**
 * A struct to represent a node in a Binary Tree
 */
struct node {
  int data;
  struct node *left;
  struct node *right;
};

typedef struct node Node;

/**
 * A signature of a function pointer
 * that can be used to traverse a binary tree.
 */
typedef void(Visitor)(Node* node);

/**
 * The different types of traversals that the binary tree can perform
 */
enum Traversal {
  INORDER = 1,   // In order traversal
  PREORDER = 2,  // Pre order traversal
  POSTORDER = 4  // Post order traversal
};

Node *initialize(int data);
void traverse(Node *node, Visitor visitor, enum Traversal traversal);
void destroy(Node *head);
void inspect(Node *head, int level);

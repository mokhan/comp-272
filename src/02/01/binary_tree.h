struct node {
  int data;
  struct node *left;
  struct node *right;
};

typedef struct node Node;
typedef void(Visitor)(Node* node);
enum Traversal { INORDER = 1, PREORDER = 2, POSTORDER = 4 };

Node *initialize(int data);
void traverse(Node *node, Visitor visitor, enum Traversal traversal);
void destroy(Node *head);
void inspect(Node *head, int level);

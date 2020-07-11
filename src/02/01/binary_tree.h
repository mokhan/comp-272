struct node {
  int data;
  struct node *left;
  struct node *right;
};

typedef struct node Node;
typedef void(Visitor)(Node* node);

Node *initialize(int data);
void preorder_traversal(Node *node, Visitor visitor);
void postorder_traversal(Node *node, Visitor visitor);
void destroy(Node *head);

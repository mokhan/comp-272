struct node {
  int data;
  struct node *next;
  struct node *prev;
};

typedef struct node Node;

Node *initialize(int data);
Node *add(Node *head, int data);
Node *get(Node *from, int index);
void swap(Node *x, Node *y);
Node *reverse(Node *head);
void inspect(Node *node);

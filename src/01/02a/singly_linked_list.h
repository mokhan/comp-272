/**
 * A node in a linked list.
 */
struct node {
  int data;
  struct node *next;
};

typedef struct node Node;

Node *initialize(int data);
Node *get(Node *from, int index);
Node *add(Node *head, int data);
void swap(Node **head, int x, int y);
void inspect(Node *node);

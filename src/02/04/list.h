typedef struct node {
  struct node *next;
  void *data;
} Node;

Node *list_initialize(void *data);
Node *list_get(Node *from, int index);
Node *list_add(Node *head, void *data);
void list_inspect(Node *node);

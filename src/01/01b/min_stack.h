struct node {
  int data;
  struct node *next;
};

typedef struct node Node;

typedef struct {
  Node *head;
} Stack;

Stack *initialize();
int size(Stack *self);
void push(Stack *self, int data);
int min(Stack *self);
int pop(Stack *self);

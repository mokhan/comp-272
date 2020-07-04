struct node {
  int data;
  struct node *next;
};

typedef struct node Node;

typedef struct {
  Node *head;
} Stack;

Stack *initialize();
void push(Stack *self, int data);
int pop(Stack *self);
int size(Stack *self);
int min(Stack *self);

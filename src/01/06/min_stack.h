struct node {
  int data;
  struct node *next;
};

typedef struct node Node;

typedef struct {
  Node *head;
  Node *min;
  int size;
} Stack;

typedef void (*Visitor)(Node *);

Stack *initialize(void);
void push(Stack *self, int data);
int pop(Stack *self);
int size(Stack *self);
int min(Stack *self);
void each(Node *head, Visitor block);
void inspect(Stack *stack);

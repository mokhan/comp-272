#include <cgreen/cgreen.h>

/*
Implement the stack methods using two queues

* `push(x)`
* `pop()`

Analyze the running time of the `push(x)` and `pop()` operations based on this implementation.
*/

struct node {
  int data;
  struct node *next;
};

typedef struct node Node;

typedef struct {
  Node *head;
  int size;
} Queue;

typedef struct {
  Queue *q1;
} Stack;

static Queue *newQueue(){
  Queue *queue = malloc(sizeof(Queue));
  queue->size = 0;
  queue->head = NULL;
  return queue;
}

static Stack *initialize() {
  Stack *stack = malloc(sizeof(Stack));
  stack->q1 = newQueue();
  return stack;
}

Node *newNode(int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void enqueue(Queue *q, int data) {
  Node *node = newNode(data);
  q->size++;

  if (q->head == NULL) {
    q->head = node;
  } else {
    Node *tail = q->head;

    while (tail->next != NULL)
      tail = tail->next;
    tail->next = node;
  }
}

int dequeue(Queue *q) {
  if (q->head == NULL) return -1;

  Node *node = q->head;
  int data = node->data;

  q->head = node->next;
  free(node);
  return data;
}

// The running time is linear time.
static void push(Stack *stack, int data) {
  enqueue(stack->q1, data);
}

// The running time is linear time.
static int pop(Stack *stack) {
  int count = stack->q1->size - 1;
  Queue *tmp = newQueue();

  for (int i = 0; i < count; i++)
    enqueue(tmp, dequeue(stack->q1));

  int data = dequeue(stack->q1);
  free(stack->q1);
  stack->q1 = tmp;
  return data;
}

int size(Stack *stack) {
  return stack->q1->size;
}

static void destroy(Stack *stack) {
  int count = size(stack);

  for (int i = 0; i < count; i++)
    pop(stack);

  free(stack->q1);
  free(stack);
}

static void inspect(Queue *q) {
  Node *tmp = q->head;

  if (q->size == 0) {
    printf("[]\n");
    return;
  }

  printf("[");
  for (int i = 0; i < q->size; i++) {
    printf("%d,", tmp->data);
    tmp = tmp->next;
  }
  printf("\b]\n");
}

Describe(Stack);
BeforeEach(Stack){ }
AfterEach(Stack){ }

Ensure(Stack, push_onto_stack) {
  Stack *stack = initialize();

  push(stack, 1);
  assert_that(size(stack), is_equal_to(1));

  push(stack, 2);
  assert_that(size(stack), is_equal_to(2));

  destroy(stack);
}

Ensure(Stack, pop_single_item) {
  Stack *stack = initialize();

  push(stack, 1);

  assert_that(pop(stack), is_equal_to(1));
  destroy(stack);
}

Ensure(Stack, pop_successive_items) {
  Stack *stack = initialize();

  push(stack, 1);
  push(stack, 2);

  assert_that(pop(stack), is_equal_to(2));
  assert_that(pop(stack), is_equal_to(1));

  destroy(stack);
}

TestSuite *stack_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, Stack, push_onto_stack);
  add_test_with_context(suite, Stack, pop_single_item);
  add_test_with_context(suite, Stack, pop_successive_items);

  return suite;
}

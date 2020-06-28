#include <cgreen/cgreen.h>

/*
   Design and implement a `MinStack` data structure that can store
   comparable elements and supports the stack operations:

 * `push(x)`
 * `pop()`
 * `size()`
 * `min()`
 All operations should run in constant time.
 */

Describe(MinStack);
BeforeEach(MinStack){ }
AfterEach(MinStack){ }

struct node {
  int data;
  struct node *next;
};

typedef struct node Node;

typedef struct {
  Node *head;
} Stack;

static Stack *initialize() {
  Stack *stack = malloc(sizeof(Stack));
  stack->head = NULL;
  return stack;
}

static int size(Stack *stack) {
  Node *current = stack->head;
  int i;
  for (i = 0; current != NULL; i++)
    current = current->next;
  return i;
}

static Node *new(int data) {
  Node *node = malloc(sizeof(Node));
  node->next = NULL;
  node->data = data;
  return node;
}

static int compare(int x, int y) {
  return x == y ? 0 : (x > y) ? 1 : -1;
}

static void insert(Node **self, int data) {
  int comparison = compare(data, (*self)->data);
  Node *node = new(data);

  switch(comparison) {
    case 1:
      if ((*self)->next)
        insert(&((*self)->next), data);
      else
        (*self)->next = node;
      break;
    case -1:
      node->next = *self;
      *self = node;
      break;
    default:
      break;
  }
}

static void push(Stack *stack, int data) {
  if (stack->head)
    insert(&stack->head, data);
  else
    stack->head = new(data);
}

static int min(Stack *stack) {
  if (stack && stack->head)
    return stack->head->data;

  return (int)NULL;
}

static int pop(Stack *stack) {
  if (!stack->head)
    return (int)NULL;

  Node *current = stack->head;
  stack->head = current->next;
  return current->data;
}

Ensure(MinStack, when_empty) {
  Stack *stack = initialize();

  assert_that(size(stack), is_equal_to(0));
  assert_that(min(stack), is_equal_to(NULL));
  assert_that(pop(stack), is_equal_to(NULL));

  free(stack);
}

Ensure(MinStack, when_pushing_a_single_integer) {
  Stack *stack = initialize();

  push(stack, 1);

  assert_that(size(stack), is_equal_to(1));
  assert_that(min(stack), is_equal_to(1));
  assert_that(pop(stack), is_equal_to(1));
  assert_that(size(stack), is_equal_to(0));

  free(stack);
}

Ensure(MinStack, when_pushing_multiple_integers_out_of_order) {
  Stack *stack = initialize();

  push(stack, 2);
  push(stack, 3);
  push(stack, 1);

  assert_that(size(stack), is_equal_to(3));
  assert_that(min(stack), is_equal_to(1));

  assert_that(pop(stack), is_equal_to(1));
  assert_that(size(stack), is_equal_to(2));

  assert_that(pop(stack), is_equal_to(2));
  assert_that(size(stack), is_equal_to(1));

  assert_that(pop(stack), is_equal_to(3));
  assert_that(size(stack), is_equal_to(0));

  assert_that(pop(stack), is_equal_to(NULL));
  assert_that(size(stack), is_equal_to(0));

  free(stack);
}

TestSuite *min_stack_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, MinStack, when_empty);
  add_test_with_context(suite, MinStack, when_pushing_a_single_integer);
  add_test_with_context(suite, MinStack, when_pushing_multiple_integers_out_of_order);
  return suite;
}

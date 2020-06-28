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
  Stack *self = malloc(sizeof(Stack));
  self->head = NULL;
  return self;
}

static int size(Stack *self) {
  Node *current = self->head;
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
    default:
      node->next = *self;
      *self = node;
      break;
  }
}

static void push(Stack *self, int data) {
  if (self->head)
    insert(&self->head, data);
  else
    self->head = new(data);
}

static int min(Stack *self) {
  if (self && self->head)
    return self->head->data;

  return (int)NULL;
}

static int pop(Stack *self) {
  if (!self->head)
    return (int)NULL;

  Node *current = self->head;
  int data = current->data;
  self->head = current->next;
  current->next = NULL;
  free(current);
  return data;
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

Ensure(MinStack, when_pushing_duplicate_values_on_to_the_stack) {
  Stack *stack = initialize();

  push(stack, 2);
  push(stack, 1);
  push(stack, 2);

  assert_that(size(stack), is_equal_to(3));
  assert_that(min(stack), is_equal_to(1));

  assert_that(pop(stack), is_equal_to(1));
  assert_that(pop(stack), is_equal_to(2));
  assert_that(pop(stack), is_equal_to(2));
  assert_that(pop(stack), is_equal_to(NULL));

  free(stack);
}

TestSuite *min_stack_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, MinStack, when_empty);
  add_test_with_context(suite, MinStack, when_pushing_a_single_integer);
  add_test_with_context(suite, MinStack, when_pushing_multiple_integers_out_of_order);
  return suite;
}

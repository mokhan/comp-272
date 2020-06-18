#include <cgreen/cgreen.h>

/*
Implement the stack methods using two queues

* `push(x)`
* `pop()`

Analyze the running time of the `push(x)` and `pop()` operations based on this implementation.
*/

typedef struct {
} Stack;

static Stack *initialize() {
  Stack *stack = malloc(sizeof(Stack));
  return stack;
}

static void push(Stack *stack, int data) {
}

static int pop(Stack *stack) {
  return 0;
}

static void destroy(Stack *stack) {
  free(stack);
}

Describe(Stack);
BeforeEach(Stack){ }
AfterEach(Stack){ }

Ensure(Stack, returns_last_item_pushed_to_stack) {
  Stack *stack = initialize();

  push(stack, 1);
  push(stack, 2);

  assert_that(pop(stack), is_equal_to(2));
  assert_that(pop(stack), is_equal_to(1));

  destroy(stack);
}

TestSuite *stack_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, Stack, returns_last_item_pushed_to_stack);

  return suite;
}

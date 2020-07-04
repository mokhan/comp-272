#include <cgreen/cgreen.h>
#include "stack.h"

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

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, stack_tests());
  return run_test_suite(suite, create_text_reporter());
}

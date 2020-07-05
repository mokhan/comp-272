#include "stack.h"
#include <cgreen/cgreen.h>
#include <math.h>

Describe(Stack);
BeforeEach(Stack) {}
AfterEach(Stack) {}

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

Ensure(Stack, when_popping_an_item_off_an_empty_stack) {
  Stack *stack = initialize();

  assert_that(pop(stack), is_equal_to(NULL));

  destroy(stack);
}

Ensure(Stack, when_pushing_an_item_on_to_a_full_stack) {
  Stack *stack = initialize();
  int max = 2147483647;

  for (int i = 0; i < max; i++)
    push(stack, 1);

  push(stack, 1);

  assert_that(size(stack), is_equal_to(max));
  destroy(stack);
}

TestSuite *stack_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, Stack, pop_single_item);
  add_test_with_context(suite, Stack, pop_successive_items);
  add_test_with_context(suite, Stack, push_onto_stack);
  add_test_with_context(suite, Stack, when_popping_an_item_off_an_empty_stack);
  add_test_with_context(suite, Stack, when_pushing_an_item_on_to_a_full_stack);

  return suite;
}

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, stack_tests());
  return run_test_suite(suite, create_text_reporter());
}

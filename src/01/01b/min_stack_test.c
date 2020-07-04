#include <cgreen/cgreen.h>
#include "min_stack.h"

Describe(MinStack);
BeforeEach(MinStack){ }
AfterEach(MinStack){ }

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

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, min_stack_tests());
  return run_test_suite(suite, create_text_reporter());
}

#include "stack.h"
#include <cgreen/cgreen.h>
#include <string.h>

Describe(Stack);
BeforeEach(Stack) {}
AfterEach(Stack) {}

Ensure(Stack, when_pushing_an_item_on_to_a_stack) {
  Stack *stack = stack_init(10);

  assert_that(stack_size(stack), is_equal_to(1));
}

TestSuite *stack_tests() {
  TestSuite *suite = create_test_suite();
  add_test_with_context(suite, Stack, when_pushing_an_item_on_to_a_stack);
  return suite;
}

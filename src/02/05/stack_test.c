#include "stack.h"
#include <cgreen/cgreen.h>
#include <string.h>

Describe(Stack);
BeforeEach(Stack) {}
AfterEach(Stack) {}

Ensure(Stack, when_pushing_an_item_on_to_a_stack) {
  Stack *stack = stack_init();

  stack_push(stack, (void *)10);

  assert_that(stack_size(stack), is_equal_to(1));
  assert_that(stack_peek(stack), is_equal_to(10));
}

Ensure(Stack, when_pushing_multiple_items_on_to_a_stack) {
  Stack *stack = stack_init();

  stack_push(stack, (void *)20);
  stack_push(stack, (void *)10);
  stack_push(stack, (void *)50);

  assert_that(stack_size(stack), is_equal_to(3));
  assert_that(stack_peek(stack), is_equal_to(50));
}

Ensure(Stack, when_pushing_a_custom_type_on_to_a_stack) {
  typedef struct {
  } Item;

  Stack *stack = stack_init();
  Item *item = malloc(sizeof(Item));

  stack_push(stack, item);

  assert_that(stack_size(stack), is_equal_to(1));
  assert_that(stack_peek(stack), is_equal_to(item));
  assert_that(stack_pop(stack), is_equal_to(item));
}

Ensure(Stack, when_popping_an_item_off_of_a_stack) {
  Stack *stack = stack_init();

  stack_push(stack, (void *)20);
  stack_push(stack, (void *)10);
  stack_push(stack, (void *)50);

  void *result = stack_pop(stack);

  assert_that(stack_size(stack), is_equal_to(2));
  assert_that(stack_peek(stack), is_equal_to(10));
  assert_that(result, is_equal_to(50));
}

TestSuite *stack_tests() {
  TestSuite *suite = create_test_suite();
  add_test_with_context(suite, Stack, when_pushing_an_item_on_to_a_stack);
  add_test_with_context(suite, Stack, when_pushing_multiple_items_on_to_a_stack);
  add_test_with_context(suite, Stack, when_pushing_a_custom_type_on_to_a_stack);
  add_test_with_context(suite, Stack, when_popping_an_item_off_of_a_stack);
  return suite;
}

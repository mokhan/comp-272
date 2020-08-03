#include "tuple.h"
#include <cgreen/cgreen.h>
#include <string.h>

Describe(Tuple);
BeforeEach(Tuple) {}
AfterEach(Tuple) {}

Ensure(Tuple, when_initializing_a_tuple) {
  Tuple *subject = tuple_initialize(21, (void *)100);

  assert_that(subject->key, is_equal_to(21));
  assert_that(subject->value, is_equal_to(100));

  tuple_destroy(subject);
}

TestSuite *tuple_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, Tuple, when_initializing_a_tuple);
  return suite;
}

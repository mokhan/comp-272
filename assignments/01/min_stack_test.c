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

Ensure(MinStack, when_getting_head) {
}

TestSuite *min_stack_tests() {
  TestSuite *suite = create_test_suite();

  /*add_test_with_context(suite, MinStack, when_pushing_it);*/
  return suite;
}

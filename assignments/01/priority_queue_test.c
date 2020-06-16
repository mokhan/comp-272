#include <cgreen/cgreen.h>
#include <string.h>

#include "priority_queue.h"

/*
Implement the methods of the priority queue interface using a singly-linked list.

* `add(x)`
* `deleteMin()`
* `size()`

Analyze the running time of the `add(x)` and `deletMin()` operations based on this implementation.
*/

Describe(PriorityQueue);
BeforeEach(PriorityQueue){ }
AfterEach(PriorityQueue){ }

Ensure(PriorityQueue, returns_size) {
  struct PriorityQueue queue = initialize();

  assert_that(count(queue), is_equal_to(0));
}

TestSuite *priority_queue_tests() {
  TestSuite *suite = create_test_suite();
  add_test_with_context(suite, PriorityQueue, returns_size);
  return suite;
}

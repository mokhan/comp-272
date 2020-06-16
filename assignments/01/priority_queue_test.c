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
  PriorityQueue *queue = initialize();

  assert_that(count(queue), is_equal_to(0));
  free(queue);
}

Ensure(PriorityQueue, adds_a_node) {
  PriorityQueue *queue = initialize();
  Node *node = create_node(1, 0);

  add(queue, node);

  assert_that(count(queue), is_equal_to(1));
  free(node);
  free(queue);
}

Ensure(PriorityQueue, removes_the_node_with_the_lowest_priority){
  PriorityQueue *queue = initialize();
  Node *min = create_node(1, 100);
  Node *mid = create_node(2, 200);
  Node *max = create_node(3, 300);

  add(queue, max);
  inspect(queue);
  add(queue, min);
  inspect(queue);
  add(queue, mid);
  inspect(queue);

  assert_that(count(queue), is_equal_to(3));
  assert_that(delete_min(queue), is_equal_to(min));
  assert_that(queue->head, is_equal_to(mid));

  free(max);
  free(mid);
  free(min);
  free(queue);
};

TestSuite *priority_queue_tests() {
  TestSuite *suite = create_test_suite();
  add_test_with_context(suite, PriorityQueue, returns_size);
  add_test_with_context(suite, PriorityQueue, adds_a_node);
  add_test_with_context(suite, PriorityQueue, removes_the_node_with_the_lowest_priority);
  return suite;
}

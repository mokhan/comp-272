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

  assert_that(size(queue), is_equal_to(0));

  destroy(queue);
}

Ensure(PriorityQueue, adds_a_node) {
  PriorityQueue *queue = initialize();

  add(queue, 1, 0);

  assert_that(size(queue), is_equal_to(1));

  destroy(queue);
}

Ensure(PriorityQueue, removes_the_node_with_the_lowest_priority){
  PriorityQueue *queue = initialize();

  add(queue, 3, 300);
  add(queue, 1, 100);
  add(queue, 2, 200);

  assert_that(size(queue), is_equal_to(3));
  assert_that(delete_min(queue), is_equal_to(100));
  assert_that(queue->head->data, is_equal_to(200));
  assert_that(size(queue), is_equal_to(2));

  destroy(queue);
};

Ensure(PriorityQueue, when_removing_node_from_empty_queue) {
  PriorityQueue *queue = initialize();

  assert_that(delete_min(queue), is_equal_to(NULL));
  assert_that(size(queue), is_equal_to(0));

  destroy(queue);
}

Ensure(PriorityQueue, when_removing_it_decreases_the_size) {
  PriorityQueue *queue = initialize();

  add(queue, 1, 0);
  delete_min(queue);

  assert_that(size(queue), is_equal_to(0));

  destroy(queue);
}

Ensure(PriorityQueue, when_removing_the_last_node_it_decrements_the_count_correctly) {
  PriorityQueue *queue = initialize();

  add(queue, 2, 200);
  add(queue, 1, 100);
  add(queue, 3, 300);

  delete_min(queue);
  delete_min(queue);
  delete_min(queue);

  assert_that(size(queue), is_equal_to(0));
  destroy(queue);
}

Ensure(PriorityQueue, when_adding_data_out_of_order) {
  PriorityQueue *queue = initialize();

  add(queue, 7, 700);
  add(queue, 3, 300);
  add(queue, 0, 100);
  add(queue, 4, 400);

  assert_that(size(queue), is_equal_to(4));
  assert_that(delete_min(queue), is_equal_to(100));
  assert_that(delete_min(queue), is_equal_to(300));
  assert_that(delete_min(queue), is_equal_to(400));
  assert_that(delete_min(queue), is_equal_to(700));
  assert_that(size(queue), is_equal_to(0));

  destroy(queue);
}

Ensure(PriorityQueue, when_adding_random_values_with_random_priority_it_returns_the_minimum_priority_value_correctly) {
  PriorityQueue *queue = initialize();
  int n = 10;

  for (int i = 0; i < n; i++)
    add(queue, rand() % 10, rand() % 1000);

  while (size(queue) > 0)
    delete_min(queue);

  assert_that(size(queue), is_equal_to(0));
  destroy(queue);
}

TestSuite *priority_queue_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, PriorityQueue, adds_a_node);
  add_test_with_context(suite, PriorityQueue, removes_the_node_with_the_lowest_priority);
  add_test_with_context(suite, PriorityQueue, returns_size);
  add_test_with_context(suite, PriorityQueue, when_adding_data_out_of_order);
  add_test_with_context(suite, PriorityQueue, when_adding_random_values_with_random_priority_it_returns_the_minimum_priority_value_correctly);
  add_test_with_context(suite, PriorityQueue, when_removing_it_decreases_the_size);
  add_test_with_context(suite, PriorityQueue, when_removing_node_from_empty_queue);
  add_test_with_context(suite, PriorityQueue, when_removing_the_last_node_it_decrements_the_count_correctly);

  return suite;
}

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, priority_queue_tests());
  return run_test_suite(suite, create_text_reporter());
}

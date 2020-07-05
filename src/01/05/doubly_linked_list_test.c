#include "doubly_linked_list.h"
#include <cgreen/cgreen.h>

Describe(DoublyLinkedList);
BeforeEach(DoublyLinkedList) {}
AfterEach(DoublyLinkedList) {}

Ensure(DoublyLinkedList, when_reversing_a_short_list) {
  Node *head = initialize(100);
  Node *mid = add(head, 200);
  Node *tail = add(head, 300);

  Node *new_head = reverse(head);

  assert_that(new_head->prev, is_equal_to(NULL));
  assert_that(new_head, is_equal_to(tail));
  assert_that(new_head->next, is_equal_to(mid));

  assert_that(mid->prev, is_equal_to(tail));
  assert_that(mid->next, is_equal_to(head));

  assert_that(head->prev, is_equal_to(mid));
  assert_that(head->next, is_equal_to(NULL));

  free(head);
}

Ensure(DoublyLinkedList, when_reversing_an_empty_list) {
  Node *head = initialize(100);
  Node *result = reverse(head);

  assert_that(result, is_equal_to(head));

  free(head);
}

TestSuite *reverse_doubly_linked_list_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, DoublyLinkedList, when_reversing_a_short_list);
  add_test_with_context(suite, DoublyLinkedList, when_reversing_an_empty_list);

  return suite;
}

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, reverse_doubly_linked_list_tests());
  return run_test_suite(suite, create_text_reporter());
}

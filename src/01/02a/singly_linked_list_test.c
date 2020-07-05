#include "singly_linked_list.h"
#include <cgreen/cgreen.h>

Describe(SinglyLinkedList);
BeforeEach(SinglyLinkedList) {}
AfterEach(SinglyLinkedList) {}

Ensure(SinglyLinkedList, when_getting_head) {
  Node *head = initialize(100);
  assert_that(get(head, 0), is_equal_to(head));
  free(head);
}

Ensure(SinglyLinkedList, when_getting_mid) {
  Node *head = initialize(100);

  Node *mid = add(head, 200);
  add(head, 300);

  assert_that(get(head, 1), is_equal_to(mid));
  assert_that(get(head, 1)->data, is_equal_to(200));

  free(head);
}

Ensure(SinglyLinkedList, when_getting_tail) {
  Node *head = initialize(100);

  add(head, 200);
  Node *tail = add(head, 300);

  assert_that(get(head, 2), is_equal_to(tail));

  free(head);
}

Ensure(SinglyLinkedList, when_getting_from_empty_list) {
  assert_that(get(NULL, 2), is_equal_to(NULL));
}

Ensure(SinglyLinkedList, when_getting_negative_index) {
  Node *head = initialize(100);

  assert_that(get(head, -1), is_equal_to(NULL));

  free(head);
}

Ensure(SinglyLinkedList, when_getting_index_out_of_range) {
  Node *head = initialize(100);

  assert_that(get(head, 1), is_equal_to(NULL));

  free(head);
}

Ensure(SinglyLinkedList, when_swapping_head) {
  Node *head = initialize(100);

  add(head, 200);
  add(head, 300);

  swap(&head, 0, 1);

  assert_that(get(head, 0), is_non_null);
  assert_that(get(head, 0)->data, is_equal_to(200));
  assert_that(get(head, 1), is_non_null);
  assert_that(get(head, 1)->data, is_equal_to(100));
  assert_that(get(head, 2), is_non_null);
  assert_that(get(head, 2)->data, is_equal_to(300));

  free(head);
}

Ensure(SinglyLinkedList, when_swapping_y_head) {
  Node *head = initialize(100);

  add(head, 200);
  add(head, 300);

  swap(&head, 1, 0);

  assert_that(get(head, 0), is_non_null);
  assert_that(get(head, 0)->data, is_equal_to(200));
  assert_that(get(head, 1), is_non_null);
  assert_that(get(head, 1)->data, is_equal_to(100));
  assert_that(get(head, 2), is_non_null);
  assert_that(get(head, 2)->data, is_equal_to(300));

  free(head);
}

Ensure(SinglyLinkedList, when_swapping_mid) {
  Node *head = initialize(100);

  add(head, 200);
  add(head, 300);
  add(head, 400);

  swap(&head, 1, 2);

  assert_that(get(head, 0)->data, is_equal_to(100));
  assert_that(get(head, 1)->data, is_equal_to(300));
  assert_that(get(head, 2)->data, is_equal_to(200));
  assert_that(get(head, 3)->data, is_equal_to(400));

  free(head);
}

Ensure(SinglyLinkedList, when_swapping_y_mid) {
  Node *head = initialize(100);

  add(head, 200);
  add(head, 300);
  add(head, 400);

  swap(&head, 2, 1);

  assert_that(get(head, 0)->data, is_equal_to(100));
  assert_that(get(head, 1)->data, is_equal_to(300));
  assert_that(get(head, 2)->data, is_equal_to(200));
  assert_that(get(head, 3)->data, is_equal_to(400));

  free(head);
}

Ensure(SinglyLinkedList, when_swapping_tail) {
  Node *head = initialize(100);

  add(head, 200);
  add(head, 300);

  swap(&head, 1, 2);

  assert_that(get(head, 0), is_non_null);
  assert_that(get(head, 0)->data, is_equal_to(100));
  assert_that(get(head, 1), is_non_null);
  assert_that(get(head, 1)->data, is_equal_to(300));
  assert_that(get(head, 2), is_non_null);
  assert_that(get(head, 2)->data, is_equal_to(200));

  free(head);
}

Ensure(SinglyLinkedList, when_swapping_index_out_of_range) {
  Node *head = initialize(100);

  add(head, 200);
  add(head, 300);

  swap(&head, 1, 3);

  assert_that(get(head, 0)->data, is_equal_to(100));
  assert_that(get(head, 1)->data, is_equal_to(200));
  assert_that(get(head, 2)->data, is_equal_to(300));

  free(head);
}

Ensure(SinglyLinkedList, when_swapping_self) {
  Node *head = initialize(100);

  swap(&head, 0, 0);

  assert_that(get(head, 0), is_non_null);
  assert_that(get(head, 0)->data, is_equal_to(100));

  free(head);
}

TestSuite *swap_singly_linked_list_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, SinglyLinkedList, when_getting_head);
  add_test_with_context(suite, SinglyLinkedList, when_getting_mid);
  add_test_with_context(suite, SinglyLinkedList, when_getting_tail);
  add_test_with_context(suite, SinglyLinkedList, when_getting_from_empty_list);
  add_test_with_context(suite, SinglyLinkedList, when_getting_negative_index);
  add_test_with_context(suite, SinglyLinkedList,
                        when_getting_index_out_of_range);

  add_test_with_context(suite, SinglyLinkedList, when_swapping_head);
  add_test_with_context(suite, SinglyLinkedList, when_swapping_y_head);
  add_test_with_context(suite, SinglyLinkedList, when_swapping_mid);
  add_test_with_context(suite, SinglyLinkedList, when_swapping_y_mid);
  add_test_with_context(suite, SinglyLinkedList, when_swapping_tail);
  add_test_with_context(suite, SinglyLinkedList,
                        when_swapping_index_out_of_range);
  add_test_with_context(suite, SinglyLinkedList, when_swapping_self);

  return suite;
}

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, swap_singly_linked_list_tests());
  return run_test_suite(suite, create_text_reporter());
}

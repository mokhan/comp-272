#include "list.h"
#include <cgreen/cgreen.h>

Describe(List);
BeforeEach(List) {}
AfterEach(List) {}

Ensure(List, when_getting_head) {
  Node *head = list_initialize((void *)100);
  assert_that(list_get(head, 0), is_equal_to(head));
  assert_that(list_get(head, 0)->data, is_equal_to(100));
  free(head);
}

Ensure(List, when_getting_mid) {
  Node *head = list_initialize((void*)100);

  Node *mid = list_add(head, (void *)200);
  list_add(head, (void *)300);

  assert_that(list_get(head, 1), is_equal_to(mid));
  assert_that(list_get(head, 1)->data, is_equal_to(200));

  free(head);
}

Ensure(List, when_getting_tail) {
  Node *head = list_initialize((void *)100);
  Node *mid = list_add(head, (void *)200);
  Node *tail = list_add(head, (void *)300);

  assert_that(list_get(head, 0), is_equal_to(head));
  assert_that(list_get(head, 0)->data, is_equal_to(100));

  assert_that(list_get(head, 1), is_equal_to(mid));
  assert_that(list_get(head, 1)->data, is_equal_to(200));

  assert_that(list_get(head, 2), is_equal_to(tail));
  assert_that(list_get(head, 2)->data, is_equal_to(300));

  free(head);
}

Ensure(List, when_getting_from_empty_list) {
  assert_that(list_get(NULL, 2), is_equal_to(NULL));
}

Ensure(List, when_getting_negative_index) {
  Node *head = list_initialize((void *)100);

  assert_that(list_get(head, -1), is_equal_to(NULL));

  free(head);
}

Ensure(List, when_getting_index_out_of_range) {
  Node *head = list_initialize((void *)100);

  assert_that(list_get(head, 1), is_equal_to(NULL));

  free(head);
}

struct Person {
  int age;
};

Ensure(List, when_adding_a_custom_datatype) {
  struct Person *item = malloc(sizeof(struct Person));
  item->age = 36;
  Node *head = list_initialize((void *)item);

  Node *result = list_get(head, 0);
  assert_that(result, is_equal_to(head));

  struct Person *p = (struct Person *)result->data;
  assert_that(p->age, is_equal_to(36));
}

TestSuite *list_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, List, when_getting_head);
  add_test_with_context(suite, List, when_getting_mid);
  add_test_with_context(suite, List, when_getting_tail);
  add_test_with_context(suite, List, when_getting_from_empty_list);
  add_test_with_context(suite, List, when_getting_negative_index);
  add_test_with_context(suite, List, when_getting_index_out_of_range);
  add_test_with_context(suite, List, when_adding_a_custom_datatype);
  return suite;
}

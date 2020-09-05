#include "sort.h"
#include <cgreen/cgreen.h>
#include <string.h>

Ensure(one_equals_one) {
  assert_that(1, is_equal_to(1));
}

Ensure(merge_sort_sorts_a_null_list) {
  merge_sort(NULL, 0);
}

Ensure(merge_sort_sorts_an_empty_list) {
  int items[] = {};

  merge_sort(items, 0);

  assert_that(sizeof(items), is_equal_to(0));
}

Ensure(merge_sort_sorts_a_list_with_one_item) {
  int items[] = {100};

  merge_sort(items, 1);

  assert_that(sizeof(items), is_equal_to(sizeof(int)));
  assert_that(items[0], is_equal_to(100));
}

Ensure(merge_sort_sorts_a_list_with_two_items) {
  int items[] = {100, 10};

  merge_sort(items, 2);

  assert_that(sizeof(items), is_equal_to(sizeof(int) * 2));
  assert_that(items[0], is_equal_to(10));
  assert_that(items[1], is_equal_to(100));
}

Ensure(merge_sort_sorts_three_unique_items) {
  int items[] = { 3, 1, 4 };

  merge_sort(items, sizeof(items) / sizeof(int));

  assert_that(items[0], is_equal_to(1));
  assert_that(items[1], is_equal_to(3));
  assert_that(items[2], is_equal_to(4));
}

Ensure(merge_sort_sorts_many_items) {
  int items[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };

  merge_sort(items, sizeof(items) / sizeof(int));

  assert_that(items[0], is_equal_to(1));
  assert_that(items[1], is_equal_to(1));
  assert_that(items[2], is_equal_to(2));
  assert_that(items[3], is_equal_to(3));
  assert_that(items[4], is_equal_to(3));
  assert_that(items[5], is_equal_to(4));
  assert_that(items[6], is_equal_to(5));
  assert_that(items[7], is_equal_to(5));
  assert_that(items[8], is_equal_to(5));
  assert_that(items[9], is_equal_to(6));
  assert_that(items[10], is_equal_to(9));
}

TestSuite *sort_tests() {
  TestSuite *x = create_test_suite();
  add_test(x, one_equals_one);

  add_test(x, merge_sort_sorts_a_null_list);
  add_test(x, merge_sort_sorts_an_empty_list);
  add_test(x, merge_sort_sorts_a_list_with_one_item);
  add_test(x, merge_sort_sorts_a_list_with_two_items);
  add_test(x, merge_sort_sorts_three_unique_items);
  add_test(x, merge_sort_sorts_many_items);
  return x;
}

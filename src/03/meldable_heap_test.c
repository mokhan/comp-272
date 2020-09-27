#include "meldable_heap.h"
#include <cgreen/cgreen.h>
#include <string.h>

Ensure(add_inserts_item_into_right_subtree) {
  MeldableHeap *heap = meldable_heap_initialize(5);
  heap = meldable_heap_add(heap, 3);

  assert_that(heap->value, is_equal_to(3));
  assert_that(heap->right->value, is_equal_to(5));
}

Ensure(add_inserts_item_into_left_subtree) {
  MeldableHeap *heap = meldable_heap_initialize(5);
  heap = meldable_heap_add(heap, 8);

  assert_that(heap->value, is_equal_to(5));
  assert_that(heap->right->value, is_equal_to(8));
}

/*
          (1)
        /      \
      (3)      (2)
     /  \     /   \
  (10)  (6) (7)   (4)
           /  \   /
         (9)  (8)(5)
*/
Ensure(add_inserts_multiple_items_into_the_subtree) {
  MeldableHeap *heap = NULL;

  for (int i = 1; i <= 10; ++i)
    heap = meldable_heap_add(heap, i);

  assert_that(heap->value, is_equal_to(1));

  assert_that(heap->right->value, is_equal_to(2));
  assert_that(heap->right->right->value, is_equal_to(4));
  assert_that(heap->right->right->left->value, is_equal_to(5));

  assert_that(heap->right->left->value, is_equal_to(7));
  assert_that(heap->right->left->left->value, is_equal_to(9));
  assert_that(heap->right->left->right->value, is_equal_to(8));

  assert_that(heap->left->value, is_equal_to(3));
  assert_that(heap->left->left->value, is_equal_to(10));
  assert_that(heap->left->right->value, is_equal_to(6));
}

/*
          (1)
        /      \
      (3)      (2)
     /  \     /   \
  (10)  (6) (7)   (4)
           /  \   /
         (9)  (8)(5)

         to

          (1)
        /      \
      (3)      (2)
     /  \     /   \
  (10)  (6)       (4)
           /  \   /
         (9)  (8)(5)
*/
Ensure(remove_removes_the_node_from_the_tree) {
  MeldableHeap *heap = NULL;

  for (int i = 1; i <= 10; ++i)
    heap = meldable_heap_add(heap, i);

  meldable_heap_inspect(heap);
  meldable_heap_remove(heap->right->left);
  meldable_heap_inspect(heap);

  assert_that(heap->value, is_equal_to(1));

  assert_that(heap->right->value, is_equal_to(2));
  assert_that(heap->right->right->value, is_equal_to(4));
  assert_that(heap->right->right->left->value, is_equal_to(5));

  assert_that(heap->right->left->value, is_equal_to(8));
  assert_that(heap->right->left->left->value, is_equal_to(9));
  assert_that(heap->right->left->right, is_equal_to(NULL));

  assert_that(heap->left->value, is_equal_to(3));
  assert_that(heap->left->left->value, is_equal_to(10));
  assert_that(heap->left->right->value, is_equal_to(6));
}

TestSuite *meldable_heap_tests() {
  TestSuite *x = create_test_suite();

  add_test(x, add_inserts_item_into_right_subtree);
  add_test(x, add_inserts_item_into_left_subtree);
  add_test(x, add_inserts_multiple_items_into_the_subtree);
  add_test(x, remove_removes_the_node_from_the_tree);
  return x;
}

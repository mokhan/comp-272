#include <cgreen/cgreen.h>
/*
Swap two adjacent elements in a list by adjusting
only the links (and not the data) using a:
* singly-linked list
* doubly-linked list
*/

Describe(SwapLinkedList);
BeforeEach(SwapLinkedList){ }
AfterEach(SwapLinkedList){ }

struct node {
  int data;
  struct node *next;
};

typedef struct node Node;

static void inspect(Node *node) {
  if (!node) return;

  printf("*******\n");
  while (node) {
    printf("\t%d\n", node->data);
    node = node->next;
  }
  printf("*******\n");
}

Node *initialize(int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

Node *add(Node *head, int data) {
  Node *tail;
  Node *tmp = head;

  while(tmp) {
    if (!tmp->next)
      break;
    tmp = tmp->next;
  }
  tail = tmp;
  tail->next = initialize(data);
  return tail->next;
}

Node *get(Node *from, int index) {
  if (!from || index < 0) return NULL;

  while(index > 0 && from){
    from = from->next;
    index--;
  }
  return from;
}

static int size(Node *head) {
  int i = 0;
  for (Node *tmp = head; tmp && tmp != NULL; tmp = tmp->next) i++;
  return i;
}

void swap(Node **head, int x, int y) {
  Node *xp, *yp, *xc, *yc, *tmp;
  int count = size(*head);

  if (x == y) return;
  if (x >= count) return;
  if (y >= count) return;

  xp = get(*head, x - 1);
  yp = get(*head, y - 1);
  xc = get(*head, x);
  yc = get(*head, y);

  if (x == 0) {
    *head = yc;
  } else {
    xp->next = yc;
  }
  if (y == 0) {
    *head = xc;
  } else {
    yp->next = xc;
  }

  tmp = yc->next;
  yc->next = xc->next;
  xc->next = tmp;
}

Ensure(SwapLinkedList, when_getting_head) {
  Node *head = initialize(100);
  assert_that(get(head, 0), is_equal_to(head));
  free(head);
}

Ensure(SwapLinkedList, when_getting_mid) {
  Node *head = initialize(100);

  Node *mid = add(head, 200);
  add(head, 300);

  assert_that(get(head, 1), is_equal_to(mid));
  assert_that(get(head, 1)->data, is_equal_to(200));

  free(head);
}

Ensure(SwapLinkedList, when_getting_tail) {
  Node *head = initialize(100);

  add(head, 200);
  Node *tail = add(head, 300);

  assert_that(get(head, 2), is_equal_to(tail));

  free(head);
}

Ensure(SwapLinkedList, when_getting_from_empty_list) {
  assert_that(get(NULL, 2), is_equal_to(NULL));
}

Ensure(SwapLinkedList, when_getting_negative_index) {
  Node *head = initialize(100);

  assert_that(get(head, -1), is_equal_to(NULL));

  free(head);
}

Ensure(SwapLinkedList, when_getting_index_out_of_range) {
  Node *head = initialize(100);

  assert_that(get(head, 1), is_equal_to(NULL));

  free(head);
}


Ensure(SwapLinkedList, when_swapping_head) {
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

Ensure(SwapLinkedList, when_swapping_y_head) {
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

Ensure(SwapLinkedList, when_swapping_mid) {
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

Ensure(SwapLinkedList, when_swapping_y_mid) {
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

Ensure(SwapLinkedList, when_swapping_tail) {
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

Ensure(SwapLinkedList, when_swapping_index_out_of_range) {
  Node *head = initialize(100);

  add(head, 200);
  add(head, 300);

  swap(&head, 1, 3);

  assert_that(get(head, 0)->data, is_equal_to(100));
  assert_that(get(head, 1)->data, is_equal_to(200));
  assert_that(get(head, 2)->data, is_equal_to(300));

  free(head);
}

Ensure(SwapLinkedList, when_swapping_self) {
  Node *head = initialize(100);

  swap(&head, 0, 0);

  assert_that(get(head, 0), is_non_null);
  assert_that(get(head, 0)->data, is_equal_to(100));

  free(head);
}

TestSuite *swap_linked_list_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, SwapLinkedList, when_getting_head);
  add_test_with_context(suite, SwapLinkedList, when_getting_mid);
  add_test_with_context(suite, SwapLinkedList, when_getting_tail);
  add_test_with_context(suite, SwapLinkedList, when_getting_from_empty_list);
  add_test_with_context(suite, SwapLinkedList, when_getting_negative_index);
  add_test_with_context(suite, SwapLinkedList, when_getting_index_out_of_range);

  add_test_with_context(suite, SwapLinkedList, when_swapping_head);
  add_test_with_context(suite, SwapLinkedList, when_swapping_y_head);
  add_test_with_context(suite, SwapLinkedList, when_swapping_mid);
  add_test_with_context(suite, SwapLinkedList, when_swapping_y_mid);
  add_test_with_context(suite, SwapLinkedList, when_swapping_tail);
  add_test_with_context(suite, SwapLinkedList, when_swapping_index_out_of_range);
  add_test_with_context(suite, SwapLinkedList, when_swapping_self);

  return suite;
}

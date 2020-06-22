#include <cgreen/cgreen.h>
/*
Swap two adjacent elements in a list by adjusting
only the links (and not the data) using a:
* singly-linked list
* doubly-linked list
*/

Describe(DoublyLinkedList);
BeforeEach(DoublyLinkedList){ }
AfterEach(DoublyLinkedList){ }

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

typedef struct node Node;

static void print(Node *node) {
  if (node->prev && node->next)
    printf("%d <- %d -> %d\n", node->prev->data, node->data, node->next->data);
  else if (node->next)
    printf("nil <- %d -> %d\n", node->data, node->next->data);
  else
    printf("%d <- %d -> nil\n", node->prev->data, node->data);
}

static void inspect(Node *node) {
  if (!node) return;

  printf("*******\n");
  while (node) {
    print(node);
    node = node->next;
  }
  printf("*******\n");
}

static Node *initialize(int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

static Node *add(Node *head, int data) {
  Node *tail;
  Node *tmp = head;

  while(tmp) {
    if (!tmp->next)
      break;
    tmp = tmp->next;
  }
  tail = tmp;
  tail->next = initialize(data);
  tail->next->prev = tail;
  return tail->next;
}

static Node *get(Node *from, int index) {
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

// nil <- 100 -> <- 200 -> <- 300 -> nil
// x: nil <- 100 -> 200
// y: 100 <- 200 -> 300
// z: 200 <- 300 -> nil
//
// nil <- 200 -> <- 100 -> <- 300 -> nil
// x: 200 <- 100 -> 300
// y: nil <- 200 -> 100
// z: 100 <- 300 -> nil
static void swap(Node *x, Node *y) {
  if (x == y) return;

  Node *xp = x->prev, *xn = x->next, *yp = y->prev, *yn = y->next;

  if (y->prev == x) {
    x->prev = y;
  } else {
    x->prev = y->prev;
  }
// x: 200 <- 100 -> 200
// y: 100 <- 200 -> 300
// z: 200 <- 300 -> nil


  x->prev->next = x;
// x: 200 <- 100 -> 200
// y: 100 <- 200 -> 100
// z: 200 <- 300 -> nil


  x->next = yn;
// x: 200 <- 100 -> 300
// y: 100 <- 200 -> 100
// z: 200 <- 300 -> nil


  x->next->prev = x;
// x: 200 <- 100 -> 300
// y: 100 <- 200 -> 100
// z: 100 <- 300 -> nil

  y->prev = xp;
// x: 200 <- 100 -> 300
// y: nil <- 200 -> 100
// z: 100 <- 300 -> nil


  /*if (y->prev) {*/
    /*y->prev->next = y;*/
  /*}*/
  /*y->next = xn;*/
  /*y->next->prev = y;*/
}

Ensure(DoublyLinkedList, when_getting_head) {
  Node *head = initialize(100);
  assert_that(get(head, 0), is_equal_to(head));
  free(head);
}

Ensure(DoublyLinkedList, when_getting_mid) {
  Node *head = initialize(100);

  Node *mid = add(head, 200);
  add(head, 300);

  assert_that(get(head, 1), is_equal_to(mid));
  assert_that(get(head, 1)->data, is_equal_to(200));

  free(head);
}

Ensure(DoublyLinkedList, when_getting_tail) {
  Node *head = initialize(100);

  add(head, 200);
  Node *tail = add(head, 300);

  assert_that(get(head, 2), is_equal_to(tail));

  free(head);
}

Ensure(DoublyLinkedList, when_getting_from_empty_list) {
  assert_that(get(NULL, 2), is_equal_to(NULL));
}

Ensure(DoublyLinkedList, when_getting_negative_index) {
  Node *head = initialize(100);

  assert_that(get(head, -1), is_equal_to(NULL));

  free(head);
}

Ensure(DoublyLinkedList, when_getting_index_out_of_range) {
  Node *head = initialize(100);

  assert_that(get(head, 1), is_equal_to(NULL));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_head) {
  Node *head = initialize(100);
  Node *mid = add(head, 200);
  Node *tail = add(head, 300);

  inspect(head);
  swap(head, mid);

  assert_that(head->data, is_equal_to(100));
  assert_that(head->prev, is_equal_to(mid));
  assert_that(head->prev->data, is_equal_to(200));
  assert_that(head->next, is_equal_to(tail));
  assert_that(head->next->data, is_equal_to(300));

  assert_that(mid->data, is_equal_to(200));
  assert_that(mid->prev, is_equal_to(NULL));
  assert_that(mid->next, is_equal_to(head));

  assert_that(tail->data, is_equal_to(300));
  assert_that(tail->prev, is_equal_to(head));
  assert_that(tail->next, is_equal_to(NULL));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_y_head) {
  Node *head = initialize(100);
  Node *mid = add(head, 200);
  Node *tail = add(head, 300);

  /*swap(&head, 1, 0);*/
  swap(mid, head);

  assert_that(get(head, 0), is_non_null);
  assert_that(get(head, 0)->data, is_equal_to(200));
  assert_that(get(head, 1), is_non_null);
  assert_that(get(head, 1)->data, is_equal_to(100));
  assert_that(get(head, 2), is_non_null);
  assert_that(get(head, 2)->data, is_equal_to(300));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_mid) {
  Node *head = initialize(100);
  Node *mid1 = add(head, 200);
  Node *mid2 = add(head, 300);
  Node *tail = add(head, 400);

  /*swap(&head, 1, 2);*/
  swap(mid1, mid2);

  assert_that(get(head, 0)->data, is_equal_to(100));
  assert_that(get(head, 1)->data, is_equal_to(300));
  assert_that(get(head, 2)->data, is_equal_to(200));
  assert_that(get(head, 3)->data, is_equal_to(400));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_y_mid) {
  Node *head = initialize(100);
  Node *mid1 = add(head, 200);
  Node *mid2 = add(head, 300);
  Node *tail = add(head, 400);

  /*swap(&head, 2, 1);*/
  swap(mid2, mid1);

  assert_that(get(head, 0)->data, is_equal_to(100));
  assert_that(get(head, 1)->data, is_equal_to(300));
  assert_that(get(head, 2)->data, is_equal_to(200));
  assert_that(get(head, 3)->data, is_equal_to(400));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_tail) {
  Node *head = initialize(100);
  Node *mid = add(head, 200);
  Node *tail = add(head, 300);

  /*swap(&head, 1, 2);*/
  swap(mid, tail);

  assert_that(get(head, 0), is_non_null);
  assert_that(get(head, 0)->data, is_equal_to(100));
  assert_that(get(head, 1), is_non_null);
  assert_that(get(head, 1)->data, is_equal_to(300));
  assert_that(get(head, 2), is_non_null);
  assert_that(get(head, 2)->data, is_equal_to(200));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_index_out_of_range) {
  Node *head = initialize(100);
  Node *mid = add(head, 200);
  Node *tail = add(head, 300);

  swap(mid, NULL);

  assert_that(get(head, 0)->data, is_equal_to(100));
  assert_that(get(head, 1)->data, is_equal_to(200));
  assert_that(get(head, 2)->data, is_equal_to(300));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_self) {
  Node *head = initialize(100);

  /*swap(&head, 0, 0);*/
  swap(head, head);

  assert_that(get(head, 0), is_non_null);
  assert_that(get(head, 0)->data, is_equal_to(100));

  free(head);
}

TestSuite *swap_doubly_linked_list_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, DoublyLinkedList, when_getting_head);
  add_test_with_context(suite, DoublyLinkedList, when_getting_mid);
  add_test_with_context(suite, DoublyLinkedList, when_getting_tail);
  add_test_with_context(suite, DoublyLinkedList, when_getting_from_empty_list);
  add_test_with_context(suite, DoublyLinkedList, when_getting_negative_index);
  add_test_with_context(suite, DoublyLinkedList, when_getting_index_out_of_range);

  add_test_with_context(suite, DoublyLinkedList, when_swapping_head);
  /*add_test_with_context(suite, DoublyLinkedList, when_swapping_y_head);*/
  /*add_test_with_context(suite, DoublyLinkedList, when_swapping_mid);*/
  /*add_test_with_context(suite, DoublyLinkedList, when_swapping_y_mid);*/
  /*add_test_with_context(suite, DoublyLinkedList, when_swapping_tail);*/
  /*add_test_with_context(suite, DoublyLinkedList, when_swapping_index_out_of_range);*/
  /*add_test_with_context(suite, DoublyLinkedList, when_swapping_self);*/

  return suite;
}

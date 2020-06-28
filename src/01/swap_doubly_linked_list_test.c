#include <cgreen/cgreen.h>
/*
Swap two adjacent elements in a list by adjusting
only the links (and not the data) using a:
* singly-linked list
* doubly-linked list
*
*
* Write a method, `reverse()`, that reverses the order of elements in a `DLList`
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

static void assign_next(Node *self, Node *other) {
  if (self)
    self->next = other;

  if (other)
    other->prev = self;
}

static void assign_prev(Node *self, Node *other) {
  if (self)
    self->prev = other;

  if (other)
    other->next = self;
}

static void swap(Node *x, Node *y) {
  if (x == y) return;
  if (!x || !y) return;
  if (x->prev == y && y->next == x) return swap(y, x);

  Node *xp = x->prev, *xn = x->next, *yp = y->prev, *yn = y->next;

  // if adjacent
  if (x->next == y && y->prev == x) {
    assign_next(x, yn);
    assign_prev(x, y);
    assign_prev(y, xp);
  } else {
    assign_prev(x, yp);
    assign_next(x, yn);
    assign_prev(y, xp);
    assign_next(y, xn);
  }
}

static Node *reverse(Node *head) {
  Node *tmp = NULL;
  Node *current = head;

  while (current != NULL) {
    tmp = current->prev;
    current->prev = current->next;
    current->next = tmp;
    current = current->prev;
  }
  return tmp ? tmp->prev : head;
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

Ensure(DoublyLinkedList, when_swapping_head_with_non_adjacent_node) {
  Node *head = initialize(100);
  Node *mid1 = add(head, 200);
  Node *mid2 = add(head, 300);
  Node *tail = add(head, 400);

  swap(head, mid2);

  assert_that(head->prev, is_equal_to(mid1));
  assert_that(head->data, is_equal_to(100));
  assert_that(head->next, is_equal_to(tail));

  assert_that(mid1->prev, is_equal_to(mid2));
  assert_that(mid1->data, is_equal_to(200));
  assert_that(mid1->next, is_equal_to(head));

  assert_that(mid2->prev, is_equal_to(NULL));
  assert_that(mid2->data, is_equal_to(300));
  assert_that(mid2->next, is_equal_to(mid1));

  assert_that(tail->prev, is_equal_to(head));
  assert_that(tail->data, is_equal_to(400));
  assert_that(tail->next, is_equal_to(NULL));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_head_with_non_adjacent_node_inverted) {
  Node *head = initialize(100);
  Node *mid1 = add(head, 200);
  Node *mid2 = add(head, 300);
  Node *tail = add(head, 400);

  swap(mid2, head);

  assert_that(head->prev, is_equal_to(mid1));
  assert_that(head->data, is_equal_to(100));
  assert_that(head->next, is_equal_to(tail));

  assert_that(mid1->prev, is_equal_to(mid2));
  assert_that(mid1->data, is_equal_to(200));
  assert_that(mid1->next, is_equal_to(head));

  assert_that(mid2->prev, is_equal_to(NULL));
  assert_that(mid2->data, is_equal_to(300));
  assert_that(mid2->next, is_equal_to(mid1));

  assert_that(tail->prev, is_equal_to(head));
  assert_that(tail->data, is_equal_to(400));
  assert_that(tail->next, is_equal_to(NULL));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_head_adjacent) {
  Node *head = initialize(100);
  Node *mid = add(head, 200);
  Node *tail = add(head, 300);

  swap(head, mid);

  assert_that(head->prev, is_equal_to(mid));
  assert_that(head->data, is_equal_to(100));
  assert_that(head->next, is_equal_to(tail));

  assert_that(mid->prev, is_equal_to(NULL));
  assert_that(mid->data, is_equal_to(200));
  assert_that(mid->next, is_equal_to(head));

  assert_that(tail->prev, is_equal_to(head));
  assert_that(tail->data, is_equal_to(300));
  assert_that(tail->next, is_equal_to(NULL));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_head_adjacent_inverted) {
  Node *head = initialize(100);
  Node *mid = add(head, 200);
  Node *tail = add(head, 300);

  swap(mid, head);

  assert_that(head->prev, is_equal_to(mid));
  assert_that(head->data, is_equal_to(100));
  assert_that(head->next, is_equal_to(tail));

  assert_that(mid->prev, is_equal_to(NULL));
  assert_that(mid->data, is_equal_to(200));
  assert_that(mid->next, is_equal_to(head));

  assert_that(tail->prev, is_equal_to(head));
  assert_that(tail->data, is_equal_to(300));
  assert_that(tail->next, is_equal_to(NULL));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_mid) {
  Node *head = initialize(100);
  Node *mid1 = add(head, 200);
  Node *mid2 = add(head, 300);
  Node *mid3 = add(head, 400);
  Node *tail = add(head, 500);

  swap(mid1, mid3);

  assert_that(head->prev, is_equal_to(NULL));
  assert_that(head->data, is_equal_to(100));
  assert_that(head->next, is_equal_to(mid3));

  assert_that(mid1->prev, is_equal_to(mid2));
  assert_that(mid1->data, is_equal_to(200));
  assert_that(mid1->next, is_equal_to(tail));

  assert_that(mid2->prev, is_equal_to(mid3));
  assert_that(mid2->data, is_equal_to(300));
  assert_that(mid2->next, is_equal_to(mid1));

  assert_that(mid3->prev, is_equal_to(head));
  assert_that(mid3->data, is_equal_to(400));
  assert_that(mid3->next, is_equal_to(mid2));

  assert_that(tail->prev, is_equal_to(mid1));
  assert_that(tail->data, is_equal_to(500));
  assert_that(tail->next, is_equal_to(NULL));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_y_mid) {
  Node *head = initialize(100);
  Node *mid1 = add(head, 200);
  Node *mid2 = add(head, 300);
  Node *mid3 = add(head, 400);
  Node *tail = add(head, 500);

  swap(mid3, mid1);

  assert_that(head->prev, is_equal_to(NULL));
  assert_that(head->data, is_equal_to(100));
  assert_that(head->next, is_equal_to(mid3));

  assert_that(mid1->prev, is_equal_to(mid2));
  assert_that(mid1->data, is_equal_to(200));
  assert_that(mid1->next, is_equal_to(tail));

  assert_that(mid2->prev, is_equal_to(mid3));
  assert_that(mid2->data, is_equal_to(300));
  assert_that(mid2->next, is_equal_to(mid1));

  assert_that(mid3->prev, is_equal_to(head));
  assert_that(mid3->data, is_equal_to(400));
  assert_that(mid3->next, is_equal_to(mid2));

  assert_that(tail->prev, is_equal_to(mid1));
  assert_that(tail->data, is_equal_to(500));
  assert_that(tail->next, is_equal_to(NULL));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_mid_adjacent) {
  Node *head = initialize(100);
  Node *mid1 = add(head, 200);
  Node *mid2 = add(head, 300);
  Node *tail = add(head, 400);

  swap(mid1, mid2);

  assert_that(head->prev, is_equal_to(NULL));
  assert_that(head->data, is_equal_to(100));
  assert_that(head->next, is_equal_to(mid2));

  assert_that(mid1->prev, is_equal_to(mid2));
  assert_that(mid1->data, is_equal_to(200));
  assert_that(mid1->next, is_equal_to(tail));

  assert_that(mid2->prev, is_equal_to(head));
  assert_that(mid2->data, is_equal_to(300));
  assert_that(mid2->next, is_equal_to(mid1));

  assert_that(tail->prev, is_equal_to(mid1));
  assert_that(tail->data, is_equal_to(400));
  assert_that(tail->next, is_equal_to(NULL));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_mid_adjacent_y) {
  Node *head = initialize(100);
  Node *mid1 = add(head, 200);
  Node *mid2 = add(head, 300);
  Node *tail = add(head, 400);

  swap(mid2, mid1);

  assert_that(head->prev, is_equal_to(NULL));
  assert_that(head->data, is_equal_to(100));
  assert_that(head->next, is_equal_to(mid2));

  assert_that(mid1->prev, is_equal_to(mid2));
  assert_that(mid1->data, is_equal_to(200));
  assert_that(mid1->next, is_equal_to(tail));

  assert_that(mid2->prev, is_equal_to(head));
  assert_that(mid2->data, is_equal_to(300));
  assert_that(mid2->next, is_equal_to(mid1));

  assert_that(tail->prev, is_equal_to(mid1));
  assert_that(tail->data, is_equal_to(400));
  assert_that(tail->next, is_equal_to(NULL));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_tail_adjacent) {
  Node *head = initialize(100);
  Node *mid = add(head, 200);
  Node *tail = add(head, 300);

  swap(mid, tail);

  assert_that(head->prev, is_equal_to(NULL));
  assert_that(head->data, is_equal_to(100));
  assert_that(head->next, is_equal_to(tail));

  assert_that(mid->prev, is_equal_to(tail));
  assert_that(mid->data, is_equal_to(200));
  assert_that(mid->next, is_equal_to(NULL));

  assert_that(tail->prev, is_equal_to(head));
  assert_that(tail->data, is_equal_to(300));
  assert_that(tail->next, is_equal_to(mid));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_tail_adjacent_inverted) {
  Node *head = initialize(100);
  Node *mid = add(head, 200);
  Node *tail = add(head, 300);

  swap(tail, mid);

  assert_that(head->prev, is_equal_to(NULL));
  assert_that(head->data, is_equal_to(100));
  assert_that(head->next, is_equal_to(tail));

  assert_that(mid->prev, is_equal_to(tail));
  assert_that(mid->data, is_equal_to(200));
  assert_that(mid->next, is_equal_to(NULL));

  assert_that(tail->prev, is_equal_to(head));
  assert_that(tail->data, is_equal_to(300));
  assert_that(tail->next, is_equal_to(mid));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_tail_with_non_adjacent_node) {
  Node *head = initialize(100);
  Node *mid1 = add(head, 200);
  Node *mid2 = add(head, 300);
  Node *tail = add(head, 400);

  swap(mid1, tail);

  assert_that(head->prev, is_equal_to(NULL));
  assert_that(head->data, is_equal_to(100));
  assert_that(head->next, is_equal_to(tail));

  assert_that(mid1->prev, is_equal_to(mid2));
  assert_that(mid1->data, is_equal_to(200));
  assert_that(mid1->next, is_equal_to(NULL));

  assert_that(mid2->prev, is_equal_to(tail));
  assert_that(mid2->data, is_equal_to(300));
  assert_that(mid2->next, is_equal_to(mid1));

  assert_that(tail->prev, is_equal_to(head));
  assert_that(tail->data, is_equal_to(400));
  assert_that(tail->next, is_equal_to(mid2));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_tail_with_non_adjacent_node_inverted) {
  Node *head = initialize(100);
  Node *mid1 = add(head, 200);
  Node *mid2 = add(head, 300);
  Node *tail = add(head, 400);

  swap(tail, mid1);

  assert_that(head->prev, is_equal_to(NULL));
  assert_that(head->data, is_equal_to(100));
  assert_that(head->next, is_equal_to(tail));

  assert_that(mid1->prev, is_equal_to(mid2));
  assert_that(mid1->data, is_equal_to(200));
  assert_that(mid1->next, is_equal_to(NULL));

  assert_that(mid2->prev, is_equal_to(tail));
  assert_that(mid2->data, is_equal_to(300));
  assert_that(mid2->next, is_equal_to(mid1));

  assert_that(tail->prev, is_equal_to(head));
  assert_that(tail->data, is_equal_to(400));
  assert_that(tail->next, is_equal_to(mid2));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_with_NULL) {
  Node *head = initialize(100);
  Node *mid = add(head, 200);
  Node *tail = add(head, 300);

  swap(mid, NULL);

  assert_that(head->prev, is_equal_to(NULL));
  assert_that(head->data, is_equal_to(100));
  assert_that(head->next, is_equal_to(mid));

  assert_that(mid->prev, is_equal_to(head));
  assert_that(mid->data, is_equal_to(200));
  assert_that(mid->next, is_equal_to(tail));

  assert_that(tail->prev, is_equal_to(mid));
  assert_that(tail->data, is_equal_to(300));
  assert_that(tail->next, is_equal_to(NULL));

  free(head);
}

Ensure(DoublyLinkedList, when_swapping_self) {
  Node *head = initialize(100);
  Node *mid = add(head, 200);
  Node *tail = add(head, 300);

  swap(mid, mid);

  assert_that(head->prev, is_equal_to(NULL));
  assert_that(head->data, is_equal_to(100));

  free(head);
}

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

TestSuite *swap_doubly_linked_list_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, DoublyLinkedList, when_getting_head);
  add_test_with_context(suite, DoublyLinkedList, when_getting_mid);
  add_test_with_context(suite, DoublyLinkedList, when_getting_tail);
  add_test_with_context(suite, DoublyLinkedList, when_getting_from_empty_list);
  add_test_with_context(suite, DoublyLinkedList, when_getting_negative_index);
  add_test_with_context(suite, DoublyLinkedList, when_getting_index_out_of_range);

  add_test_with_context(suite, DoublyLinkedList, when_swapping_head_adjacent);
  add_test_with_context(suite, DoublyLinkedList, when_swapping_head_adjacent_inverted);
  add_test_with_context(suite, DoublyLinkedList, when_swapping_head_with_non_adjacent_node);
  add_test_with_context(suite, DoublyLinkedList, when_swapping_head_with_non_adjacent_node_inverted);
  add_test_with_context(suite, DoublyLinkedList, when_swapping_mid);
  add_test_with_context(suite, DoublyLinkedList, when_swapping_y_mid);
  add_test_with_context(suite, DoublyLinkedList, when_swapping_mid_adjacent);
  add_test_with_context(suite, DoublyLinkedList, when_swapping_mid_adjacent_y);
  add_test_with_context(suite, DoublyLinkedList, when_swapping_tail_adjacent);
  add_test_with_context(suite, DoublyLinkedList, when_swapping_tail_adjacent_inverted);
  add_test_with_context(suite, DoublyLinkedList, when_swapping_tail_with_non_adjacent_node);
  add_test_with_context(suite, DoublyLinkedList, when_swapping_tail_with_non_adjacent_node_inverted);
  add_test_with_context(suite, DoublyLinkedList, when_swapping_with_NULL);
  add_test_with_context(suite, DoublyLinkedList, when_swapping_self);

  add_test_with_context(suite, DoublyLinkedList, when_reversing_a_short_list);
  add_test_with_context(suite, DoublyLinkedList, when_reversing_an_empty_list);

  return suite;
}
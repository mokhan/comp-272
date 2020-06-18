#include <cgreen/cgreen.h>
#include <string.h>

/*
Implement the methods of the priority queue interface using a singly-linked list.

* `add(x)`
* `deleteMin()`
* `size()`

Analyze the running time of the `add(x)` and `deletMin()` operations based on this implementation.
*/
struct node {
  int priority;
  int data;
  struct node *next;
};

typedef struct node Node;

typedef struct {
  Node *head;
  int size;
} PriorityQueue;


// https://en.wikipedia.org/wiki/Priority_queue
static PriorityQueue *initialize() {
  PriorityQueue *queue = malloc(sizeof(PriorityQueue));
  queue->size = 0;
  queue->head = NULL;
  return queue;
}

static Node *create_node(int priority, int data) {
  Node *node = malloc(sizeof(Node));
  node->priority = priority;
  node->data = data;
  node->next = NULL;
  return node;
}

// This function is constant time O(1)
static int size(PriorityQueue *queue) {
  return queue->size;
}

// This function is linear time O(n)
static void add(PriorityQueue *queue, Node *node) {
  queue->size++;

  if (queue->head == NULL) {
    queue->head = node;
    return;
  }

  Node *tmp = queue->head;
  Node *prev = NULL;

  while(tmp != NULL) {
    if (tmp->data > node->data) {
      node->next = tmp;
      if (tmp == queue->head)
        queue->head = node;
      else if (prev != NULL)
        prev->next = node;
      break;
    }
    prev = tmp;
    tmp = tmp->next;
  }
}

// This function is constant time O(1)
static Node *delete_min(PriorityQueue *queue) {
  Node *tmp = queue->head;
  queue->head = tmp->next;
  return tmp;
}

static void inspect(PriorityQueue *queue) {
  Node *tmp = queue->head;

  while(tmp) {
    printf("%d\n", tmp->data);
    tmp = tmp->next;
  }
}

static void destroy(PriorityQueue *queue) {
  Node *current = queue->head;
  Node *tmp;

  while(current) {
    tmp = current, current = current->next;

    if (tmp) free(tmp);
  }
  free(queue);
}

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
  Node *node = create_node(1, 0);

  add(queue, node);

  assert_that(size(queue), is_equal_to(1));

  destroy(queue);
}

Ensure(PriorityQueue, removes_the_node_with_the_lowest_priority){
  PriorityQueue *queue = initialize();
  Node *min = create_node(1, 100);
  Node *mid = create_node(2, 200);
  Node *max = create_node(3, 300);

  add(queue, max);
  add(queue, min);
  add(queue, mid);

  assert_that(size(queue), is_equal_to(3));
  assert_that(delete_min(queue), is_equal_to(min));
  assert_that(queue->head, is_equal_to(mid));

  destroy(queue);
};

TestSuite *priority_queue_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, PriorityQueue, returns_size);
  add_test_with_context(suite, PriorityQueue, adds_a_node);
  add_test_with_context(suite, PriorityQueue, removes_the_node_with_the_lowest_priority);

  return suite;
}

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

static int MAX_SIZE = 2147483647;

/**
 * Constructs a new instance of a queue
 *
 * @return A Queue struct
 */
static Queue *newQueue(void){
  Queue *queue = malloc(sizeof(Queue));
  queue->size = 0;
  queue->head = NULL;
  return queue;
}

/**
 * Constructs an instance of a Stack.
 *
 * @return A Stack struct.
 */
Stack *initialize(void) {
  Stack *stack = malloc(sizeof(Stack));
  stack->q1 = newQueue();
  return stack;
}

/**
 * Constructs a new singly linked list Node to push onto the Stack.
 *
 * @param data The data to store on the stack.
 * @return A Node struct
 */
Node *newNode(int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

/**
 * Enqueues a new item onto a Queue
 *
 * @param self The queue to add the data to
 * @param data The data to add to the queue
 */
void enqueue(Queue *self, int data) {
  Node *node = newNode(data);
  self->size++;

  if (self->head == NULL) {
    self->head = node;
  } else {
    Node *tail = self->head;

    while (tail->next != NULL)
      tail = tail->next;
    tail->next = node;
  }
}

/**
 * Dequeues the next item from the queue
 *
 * @param self The queue to dequeue from
 * @return The data for the next it to remove from the Queue
 */
int dequeue(Queue *self) {
  if (self->head == NULL) return -1;

  Node *node = self->head;
  int data = node->data;

  self->head = node->next;
  free(node);
  return data;
}

/**
 * Pushes an item on to the top of a stack.
 *
 * @param self The stack to push the data on to
 * @param data The data to push on to the stack
 */
void push(Stack *self, int data) {
  if (self->q1->size < MAX_SIZE)
    enqueue(self->q1, data);
}

/**
 * Pops off the last item pushed onto the stack.
 *
 * @param self The stack to pop an item off of
 * @return The data associated with the item to pop off the stack
 */
int pop(Stack *self) {
  int count = self->q1->size;

  if (count <= 0)
    return 0;

  Queue *tmp = newQueue();

  for (int i = 0; i < count - 1; i++)
    enqueue(tmp, dequeue(self->q1));

  int data = dequeue(self->q1);
  free(self->q1);
  self->q1 = tmp;
  return data;
}

/**
 * Returns the number of items on the stack
 *
 * @param self The stack to investigate
 * @return The count of items on the stack.
 */
int size(Stack *self) {
  return self->q1->size;
}

/**
 * The equivalent of a destructor to free any memory associated with a Stack.
 *
 * @param self The stack to clean up
 */
void destroy(Stack *self) {
  int count = size(self);

  for (int i = 0; i < count; i++)
    pop(self);

  free(self->q1);
  free(self);
}

/**
 * A helper method used to print the items in a queue
 *
 * @param self the queue to print
 */
void inspect(Queue *self) {
  Node *tmp = self->head;

  if (self->size == 0) {
    printf("[]\n");
    return;
  }

  printf("[");
  for (int i = 0; i < self->size; i++) {
    printf("%d,", tmp->data);
    tmp = tmp->next;
  }
  printf("\b]\n");
}

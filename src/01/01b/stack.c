#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

static Queue *newQueue(){
  Queue *queue = malloc(sizeof(Queue));
  queue->size = 0;
  queue->head = NULL;
  return queue;
}

Stack *initialize() {
  Stack *stack = malloc(sizeof(Stack));
  stack->q1 = newQueue();
  return stack;
}

Node *newNode(int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void enqueue(Queue *q, int data) {
  Node *node = newNode(data);
  q->size++;

  if (q->head == NULL) {
    q->head = node;
  } else {
    Node *tail = q->head;

    while (tail->next != NULL)
      tail = tail->next;
    tail->next = node;
  }
}

int dequeue(Queue *q) {
  if (q->head == NULL) return -1;

  Node *node = q->head;
  int data = node->data;

  q->head = node->next;
  free(node);
  return data;
}

// The running time is linear time.
void push(Stack *stack, int data) {
  enqueue(stack->q1, data);
}

// The running time is linear time.
int pop(Stack *stack) {
  int count = stack->q1->size - 1;
  Queue *tmp = newQueue();

  for (int i = 0; i < count; i++)
    enqueue(tmp, dequeue(stack->q1));

  int data = dequeue(stack->q1);
  free(stack->q1);
  stack->q1 = tmp;
  return data;
}

int size(Stack *stack) {
  return stack->q1->size;
}

void destroy(Stack *stack) {
  int count = size(stack);

  for (int i = 0; i < count; i++)
    pop(stack);

  free(stack->q1);
  free(stack);
}

static void inspect(Queue *q) {
  Node *tmp = q->head;

  if (q->size == 0) {
    printf("[]\n");
    return;
  }

  printf("[");
  for (int i = 0; i < q->size; i++) {
    printf("%d,", tmp->data);
    tmp = tmp->next;
  }
  printf("\b]\n");
}


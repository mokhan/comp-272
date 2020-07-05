#include "min_stack.h"
#include <stdio.h>
#include <stdlib.h>

void inspect(Stack *stack)
{
  Node *head = stack->head;

  while(head) {
    printf("\t [%7d]\n", head->data);
    head = head->next;
  }
}

int main(int argc, char *argv[])
{
  printf("=== COMP-272 - Assignment 1 - Question 6 ===\n");

  Stack *stack = initialize();

  for (int i = 0; i < 10; i++) {
    int data = rand() % 100;
    printf("Push: %d\n", data);
    push(stack, data);
    inspect(stack);
  }

  while(size(stack) > 0) {
    printf("Pop: %d\n", pop(stack));
    inspect(stack);
  }

  free(stack);
  return 0;
}

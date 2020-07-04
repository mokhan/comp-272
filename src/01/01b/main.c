#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  printf("=== COMP-272 - Assignment 1 - Question 1b ===\n");
  Stack *stack = initialize();

  for (int i = 0; i < 10; i++) {
    int data = rand() % 1000;

    printf("Push: %d\n", data);
    push(stack, data);
  }

  printf("\n");
  inspect(stack->q1);

  while (size(stack) > 0) {
    printf("Pop: %d\n", pop(stack));
    inspect(stack->q1);
  }
  printf("Bye\n");
  return 0;
}

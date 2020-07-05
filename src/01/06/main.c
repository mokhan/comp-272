#include "min_stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  Stack *stack = initialize();

  printf("=== COMP-272 - Assignment 1 - Question 6 ===\n");
  printf("Pushing:\n==========\n");
  int n = 25;
  for (int i = 0; i < n; i++) {
    int data = rand() % n;
    push(stack, data);
    printf("Push: %d, Min: %d\n", data, min(stack));
    inspect(stack);
  }

  printf("Popping:\n==========\n");
  inspect(stack);
  while(size(stack) > 0) {
    printf("Pop: %d, Min: %d\n", pop(stack), min(stack));
    inspect(stack);
  }

  printf("Bye\n");
  free(stack);
  return 0;
}

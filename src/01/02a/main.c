#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int next(void) {
  return rand() % 100;
}

int main(int argc, char *argv[])
{
  printf("=== COMP-272 - Assignment 1 - Question 2a ===\n");
  Node *head = initialize(next());

  for (int i = 0; i < 9; i++)
    add(head, next());

  printf("\n\t");
  inspect(head);

  for (int i = 0; i < 10; i+=2){
    swap(&head, i, i+1);
    printf("swap: %d,%d\n\t", i, i+1);
    inspect(head);
  }

  return 0;
}

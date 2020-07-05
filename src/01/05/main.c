#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int next(void) {
  return rand() % 100;
}

int main(int argc, char *argv[])
{
  printf("=== COMP-272 - Assignment 1 - Question 5 ===\n");

  Node *head = initialize(0);

  for (int i = 0; i < 10; i++)
    add(head, i);

  printf("Before:\n\t");
  inspect(head);

  printf("Reversing...\n");
  head = reverse(head);

  printf("After:\n\t");
  inspect(head);

  return 0;
}

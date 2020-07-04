#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int next(void) {
  return rand() % 100;
}

int main(int argc, char *argv[])
{
  printf("=== COMP-272 - Assignment 1 - Question 2b ===\n");
  Node *head = initialize(next());

  return 0;
}

#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int next(void) { return rand() % 100; }

int main(int argc, char *argv[]) {
  printf("=== COMP-272 - Assignment 1 - Question 2b ===\n");
  Node *head = initialize(next());
  Node *new_head = NULL;

  for (int i = 0; i < 9; ++i)
    add(head, next());

  printf("\t");
  inspect(head);

  new_head = get(head, 1);
  swap(head, new_head);
  head = new_head;
  printf("swap: 0,1\n\t");
  inspect(head);

  for (int i = 2; i < 10; i += 2) {
    swap(get(head, i), get(head, i + 1));
    printf("swap: %d,%d\n\t", i, i + 1);
    inspect(head);
  }

  return 0;
}

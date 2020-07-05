#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("=== COMP-272 - Assignment 1 - Question 1a ===\n");
  PriorityQueue *queue = initialize();

  for (int i = 0; i < 10; i++) {
    int priority = rand() % 10;
    int data = rand() % 1000;

    printf("Enqueue: %d\t%d\n", priority, data);
    add(queue, priority, data);
  }

  printf("\n");
  while (size(queue) > 0) {
    printf("Dequeue: %d\n", delete_min(queue));
    inspect(queue);
  }
  printf("Bye\n");
  return 0;
}

#include <stdio.h>
#include "priority_queue.h"

int main(int argc, char *argv[])
{
  printf("hello world\n");

  PriorityQueue *queue = initialize();

  add(queue, create_node(2, 200));
  add(queue, create_node(1, 100));
  add(queue, create_node(3, 300));

  printf("%d\n", size(queue));

  while (size(queue) > 0) {
    Node *tmp = delete_min(queue);
    if (tmp)
      printf("%d\n", tmp->data);
    else
      printf("%d\n", size(queue));
  }
  printf("Bye\n");
  return 0;
}

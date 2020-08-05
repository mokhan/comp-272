#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Node *nodes[32];
static int visited_count;

static void visitor(Node *node) {
  nodes[visited_count] = node;
  visited_count++;
}

int main(int argc, char *argv[]) {
  printf("=== COMP-272 - Assignment 02 - Question 01 ===\n");

  Node *a = initialize(100);
  Node *b = initialize(200);
  Node *c = initialize(300);
  Node *d = initialize(400);
  Node *e = initialize(500);

  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  inspect(a, 0);

  printf("\n=== Preorder traversal ===\n");
  int visited_count = 0;
  memset(nodes, 0, sizeof(nodes));

  traverse(a, visitor, PREORDER);

  for (int i = 0; i < visited_count; i++) {
    printf("%d", nodes[i]->data);
  }

  return 0;
}

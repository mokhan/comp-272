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

void print_traversal(Node *tree, enum Traversal direction) {
  visited_count = 0;
  memset(nodes, 0, sizeof(nodes));

  traverse(tree, visitor, direction);

  for (int i = 0; i < visited_count; i++)
    printf("%d ", nodes[i]->data);
  printf("\n");
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

  printf("\n=== Pre order traversal ===\n");
  print_traversal(a, PREORDER);

  printf("\n=== In order traversal ===\n");
  print_traversal(a, INORDER);

  printf("\n=== Post order traversal ===\n");
  print_traversal(a, POSTORDER);

  return 0;
}

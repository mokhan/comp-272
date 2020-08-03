#include <stdio.h>
#include "hash.h"

int main(int argc, char *argv[]) {
  printf("=== COMP-272 - Assignment 02 - Question 04 ===\n");
  Hash *hash = hash_init(13);
  int items[] = {1, 5, 21, 26, 39, 14, 15, 16, 17, 18, 19, 20, 111, 145, 146};
  int n = sizeof(items) / sizeof(int);

  printf("Insert items into hash\n");
  for (int i = 0; i < n; i++) {
    int key = items[i];
    long value = key * 10;
    printf("(%d:%d) ", key, value);
    hash_set(hash, key, (void *)value);
  }

  printf("\nInspect hash table\n");
  hash_inspect(hash);

  printf("Retrieve each item from the table\n");
  for (int i = 0; i < n; i++) {
    int key = items[i];
    printf("(%d:%d) ", key, hash_get(hash, key));
  }

  printf("\nBye\n");
  return 0;
}

#include "hash.h"
#include "tuple.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Hash *hash_init(int size) {
  Hash *hash = malloc(sizeof(Hash));
  hash->size = size;
  hash->buckets = calloc(size, sizeof(Node));
  return hash;
}

unsigned int hash_index(Hash *hash, int key) { return key % hash->size; }

void *search(Node *list, int key) {
  Node *current = list;

  while (current) {
    Tuple *t = current->data;
    if (t->key == key)
      return t->value;
    current = current->next;
  }

  return NULL;
}

void *hash_get(Hash *hash, int key) {
  unsigned int bucket = hash_index(hash, key);
  Node *n = hash->buckets + bucket;
  return (n->data) ? search(n, key) : NULL;
}

void hash_set(Hash *hash, int key, void *value) {
  unsigned int bucket = hash_index(hash, key);
  Tuple *tuple = tuple_initialize(key, value);
  Node *n = hash->buckets + bucket;

  if (n->data)
    list_add(n, tuple);
  else
    hash->buckets[bucket] = *list_initialize(tuple);
}

void print_tuple(void *data) {
  Tuple *t = data;

  if (t)
    printf("(%d:%d)", t->key, t->value);
  else
    printf("(nil)");
}

void hash_inspect(Hash *hash) {
  for (int i = 0; i < hash->size; i++) {
    printf("%2d: ", i);
    list_inspect(hash->buckets + i, print_tuple);
  }
}

#include "hash.h"
#include "tuple.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Hash *hash_init(int size)
{
  Hash *hash = malloc(sizeof(Hash));
  hash->size = size;
  hash->buckets = calloc(size, sizeof(Node));
  return hash;
}

int hash_index(Hash *hash, int key)
{
  return key % hash->size;
}

void *hash_get(Hash *hash, int key)
{
  int bucket = hash_index(hash, key);
  Node *list = hash->buckets + bucket;
  if (list && list->data)
    return ((Tuple *)list->data)->value;
  else
    return NULL;
}

void hash_set(Hash *hash, int key, void *value)
{
  int bucket = hash_index(hash, key);
  Node *node = list_initialize(tuple_initialize(key, value));
  hash->buckets[bucket] = *node;
  hash_inspect(hash);
}

void hash_inspect(Hash *hash)
{
  for (int i = 0; i < hash->size; i++) {
    printf("%2d: ", i);
    list_inspect(hash->buckets + i);
  }
}

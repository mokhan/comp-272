#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int to_hash(int key)
{
  return key % 13;
}

Hash *hash_init(int size)
{
  Hash *hash = malloc(sizeof(Hash));
  hash->size = size;
  return hash;
}

int hash_get(Hash *hash, int key)
{
  int bucket = to_hash(key);
  Node node = hash->buckets[bucket];
  return node.data;
}

void hash_set(Hash *hash, int key, int value)
{
  int bucket = to_hash(key);
  Node node = hash->buckets[bucket];
  node.data = value;
  return;
}

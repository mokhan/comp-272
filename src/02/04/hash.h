#include "list.h"

typedef struct {
  int key;
  void *value;
} Tuple;

typedef struct {
  Node *head;
} Hash;

Hash *hash_init(int buckets);
void *hash_get(Hash *hash, int key);
void hash_set(Hash *hash, int key, void **value);

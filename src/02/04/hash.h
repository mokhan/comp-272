#include "list.h"

typedef struct {
  Node *buckets;
  int size;
} Hash;

Hash *hash_init(int buckets);
void *hash_get(Hash *hash, int key);
void hash_set(Hash *hash, int key, void *value);
void hash_inspect(Hash *hash);

typedef struct node {
  struct node *next;
  int data;
} Node;

typedef struct {
  Node buckets[13];
  int size;
} Hash;

Hash *hash_init(int size);
int hash_get(Hash *hash, int key);
void hash_set(Hash *hash, int key, int value);

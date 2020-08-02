typedef struct node {
  struct node *next;
  void *value;
} Node;

typedef struct {
  Node *head;
} Hash;

Hash *hash_init(int buckets);
void *hash_get(Hash *hash, int key);
void hash_set(Hash *hash, int key, void *value);

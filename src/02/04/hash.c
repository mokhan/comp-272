#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int to_hash(int key)
{
  return key % 13;
}

Hash *hash_init(int buckets)
{
  Hash *hash = malloc(sizeof(Hash));
  /*hash->head = node_initialize(NULL);*/
  /*Node *current = hash->head;*/

  /*for (int i = 1; i < buckets; i++) {*/
    /*current->next = node_initialize(NULL);*/
    /*current = current->next;*/
  /*}*/
  return hash;
}

void *hash_get(Hash *hash, int key)
{
  /*int bucket = to_hash(key);*/
  /*Node *node = node_at(hash->head, bucket);*/
  /*node_inspect(hash->head);*/
  /*printf("  ");*/
  /*node_inspect(node);*/

  /*if (!node->value) {*/
    /*return NULL;*/
  /*}*/

  /*Tuple *t = (Tuple *)node->value;*/
  /*if (t->key == key) {*/
    /*return node->value;*/
  /*}*/

  /*return node->value;*/
  return NULL;
}

void hash_set(Hash *hash, int key, void **value)
{
  int bucket = to_hash(key);
  /*Node *node = node_at(hash->head, bucket);*/
  /*Tuple *tuple = malloc(sizeof(Tuple));*/
  /*tuple->key = key;*/
  /*tuple->value = value;*/
  /*list_add(node, tuple);*/
}

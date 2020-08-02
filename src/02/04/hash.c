#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int to_hash(int key)
{
  return key % 13;
}

Node *node_init()
{
  Node *node = malloc(sizeof(Node));
  node->next = NULL;
  node->value = NULL;
  return node;
}

Node *node_at(Node *head, int index)
{
  Node *current = head;

  for (int i = 0; i < index; i++)
    current = current->next;

  return current;
}

void node_inspect(Node *node)
{
  if (!node)
    return;

  int i = 0;
  while (node) {
    printf("[%d: %3p]", i, node->value);
    node = node->next;
    i++;
  }
  printf("\n");
}

Hash *hash_init(int buckets)
{
  Hash *hash = malloc(sizeof(Hash));
  hash->head = node_init();
  Node *current = hash->head;

  for (int i = 1; i < buckets; i++) {
    current->next = node_init();
    current = current->next;
  }
  return hash;
}

void *hash_get(Hash *hash, int key)
{
  int bucket = to_hash(key);
  Node *node = node_at(hash->head, bucket);
  node_inspect(hash->head);
  return node->value;
}

void hash_set(Hash *hash, int key, void **value)
{
  int bucket = to_hash(key);
  Node *node = node_at(hash->head, bucket);
  node->value = value;
}

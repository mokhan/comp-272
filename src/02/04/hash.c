#include "hash.h"
#include "tuple.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Initialize a new hash table.
 *
 * @param size The number of buckets to allocate for the chash table.
 * @return Returns the hash table.
 */
Hash *hash_init(int size) {
  Hash *hash = malloc(sizeof(Hash));
  hash->size = size;
  hash->buckets = calloc(size, sizeof(Node));
  return hash;
}

/**
 * Computes a hash code for the given key.
 *
 * @param hash The hash table that the key is used in.
 * @param key The key to produce a hash code for
 * @return Returns a hash code for the given key.
 */
unsigned int hash_code(Hash *hash, int key) { return key % hash->size; }

/**
 * A function to search for a specific key in a linked list.
 * This performs a O(n) search to find the matching key.
 * A possible optimization would be to convert this to do a binary
 * search for the given key using a binary search tree instead of a linked
 * list.
 *
 * @param list The linked list to search for the given key
 * @param key The key to search for in the linked list
 * @return Returns the data associated with the given key.
 */
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

/**
 * A function to fetch a specify value from a hash table by key.
 *
 * @param hash The hash table to search.
 * @param key The key associated with the value to return
 * @return Returns the data associated with the key or NULL if the key is not
 * found.
 */
void *hash_get(Hash *hash, int key) {
  unsigned int bucket = hash_code(hash, key);
  Node *n = hash->buckets + bucket;
  return (n->data) ? search(n, key) : NULL;
}

/**
 * A function to set the value associated with a key
 * in a hash table.
 *
 * @param hash The hash table to insert the key/value pair into
 * @param key The key associated with the value to insert.
 * @param value The value associated with the key to insert.
 */
void hash_set(Hash *hash, int key, void *value) {
  unsigned int bucket = hash_code(hash, key);
  Tuple *tuple = tuple_initialize(key, value);
  Node *n = hash->buckets + bucket;

  if (n->data)
    list_add(n, tuple);
  else
    hash->buckets[bucket] = *list_initialize(tuple);
}

/**
 * A function that pretty prints a key/value pair.
 *
 * @param data The Tuple to print.
 */
void print_tuple(void *data) {
  Tuple *t = data;

  if (t)
    printf("(%d:%d)", t->key, t->value);
  else
    printf("(nil)");
}

/**
 * Prints a visual representation of a hash table.
 *
 * @param hash The hash table to inspect
 */
void hash_inspect(Hash *hash) {
  for (int i = 0; i < hash->size; i++) {
    printf("%2d: ", i);
    list_inspect(hash->buckets + i, print_tuple);
  }
}

#include "tuple.h"
#include "stdlib.h"

/**
 * Initializes a new tuple bound to a key/value pair.
 *
 * @param key The key to bind to
 * @param value The value to bind to
 * @return Returns a new Tuple
 */
Tuple *tuple_initialize(int key, void *value) {
  Tuple *tuple = malloc(sizeof(Tuple));
  tuple->key = key;
  tuple->value = value;
  return tuple;
}

/**
 * A destructor for a Tuple
 *
 * @param tuple The tuple to free
 */
void tuple_destroy(Tuple *tuple) { return free(tuple); }

#include "tuple.h"
#include "stdlib.h"

Tuple *tuple_initialize(int key, void *value) {
  Tuple *tuple = malloc(sizeof(Tuple));
  tuple->key = key;
  tuple->value = value;
  return tuple;
}

void tuple_destroy(Tuple *tuple) { return free(tuple); }

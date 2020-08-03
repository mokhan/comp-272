#include "stdlib.h"
#include "tuple.h"

Tuple *tuple_initialize(int key, int value)
{
  Tuple *tuple = malloc(sizeof(Tuple));
  tuple->key = key;
  tuple->value = value;
  return tuple;
}

void tuple_destroy(Tuple *tuple)
{
  return free(tuple);
}

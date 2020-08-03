typedef struct {
  int key;
  int value;
} Tuple;

Tuple *tuple_initialize(int key, int value);
void tuple_destroy(Tuple *tuple);

typedef struct {
  int key;
  void *value;
} Tuple;

Tuple *tuple_initialize(int key, void *value);
void tuple_destroy(Tuple *tuple);

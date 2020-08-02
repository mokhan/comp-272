#include "hash.h"
#include <cgreen/cgreen.h>
#include <string.h>

Describe(HashTable);
BeforeEach(HashTable) {}
AfterEach(HashTable) {}

Ensure(HashTable, when_initializing_a_hash) {
  Hash *hash = hash_init(13);

  assert_that(hash, is_not_equal_to(NULL));
}

Ensure(HashTable, when_getting_a_value_for_a_key_that_has_not_been_inserted) {
  Hash *hash = hash_init(13);

  assert_that(hash_get(hash, 1), is_equal_to(NULL));
}

Ensure(HashTable, when_getting_a_values_for_a_key_that_has_been_inserted) {
  int key = 7;
  int value = 100;
  Hash *hash = hash_init(13);

  hash_set(hash, key, &value);
  assert_that(*(int *)hash_get(hash, key), is_equal_to(value));
}

TestSuite *hash_table_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, HashTable, when_initializing_a_hash);
  add_test_with_context(suite, HashTable, when_getting_a_value_for_a_key_that_has_not_been_inserted);
  add_test_with_context(suite, HashTable, when_getting_a_values_for_a_key_that_has_been_inserted);
  return suite;
}

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, hash_table_tests());
  return run_test_suite(suite, create_text_reporter());
}

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
  Hash *hash = hash_init(13);
  int key = 7;

  hash_set(hash, key, (void *)100);
  assert_that(hash_get(hash, key), is_equal_to(100));
}

Ensure(HashTable, when_a_hash_collision_occurs) {
  Hash *hash = hash_init(13);

  hash_set(hash, 8, (void *)80);
  hash_set(hash, 21, (void *)210);

  assert_that(hash_get(hash, 8), is_equal_to(80));
  assert_that(hash_get(hash, 21), is_equal_to(210));
}

Ensure(HashTable, when_inserting_multiple_items_into_the_hash_table) {
  Hash *hash = hash_init(13);
  int items[] = {1, 5, 21, 26, 39, 14, 15, 16, 17, 18, 19, 20, 111, 145, 146};
  int n = sizeof(items) / sizeof(int);

  for (int i = 0; i < n; i++) {
    int key = items[i];
    long value = key * 10;
    hash_set(hash, key, (void *)value);
  }

  for (int i = 0; i < n; i++) {
    int key = items[i];
    assert_that(hash_get(hash, key), is_equal_to(key * 10));
  }
}

TestSuite *hash_table_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, HashTable, when_initializing_a_hash);
  add_test_with_context(
      suite, HashTable,
      when_getting_a_value_for_a_key_that_has_not_been_inserted);
  add_test_with_context(suite, HashTable,
                        when_getting_a_values_for_a_key_that_has_been_inserted);
  add_test_with_context(suite, HashTable, when_a_hash_collision_occurs);
  add_test_with_context(suite, HashTable,
                        when_inserting_multiple_items_into_the_hash_table);
  return suite;
}

extern TestSuite *list_tests();
extern TestSuite *tuple_tests();

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, hash_table_tests());
  add_suite(suite, list_tests());
  add_suite(suite, tuple_tests());
  return run_test_suite(suite, create_text_reporter());
}

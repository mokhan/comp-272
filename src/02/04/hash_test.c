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

TestSuite *hash_table_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, HashTable, when_initializing_a_hash);
  return suite;
}

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, hash_table_tests());
  return run_test_suite(suite, create_text_reporter());
}

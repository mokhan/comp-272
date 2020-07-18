#include "btree.h"
#include <cgreen/cgreen.h>
#include <string.h>

Describe(BinaryTree);
BeforeEach(BinaryTree) {}
AfterEach(BinaryTree) {}

Ensure(BinaryTree, when_a_tree_is_NULL) {
  bool result = btree_is_bst(NULL);

  assert_that(result, is_equal_to(false));
}

Ensure(BinaryTree, when_a_tree_has_a_single_node) {
  BTree *tree = btree_init(100);
  bool result = btree_is_bst(tree);

  assert_that(result, is_equal_to(true));
}

TestSuite *binary_search_tree_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, BinaryTree, when_a_tree_is_NULL);
  add_test_with_context(suite, BinaryTree, when_a_tree_has_a_single_node);

  return suite;
}

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, binary_search_tree_tests());
  return run_test_suite(suite, create_text_reporter());
}

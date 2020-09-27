#include "btree.h"
#include "rb_tree.h"
#include <cgreen/cgreen.h>
#include <math.h>
#include <string.h>

Ensure(initialize_returns_new_btree) {
  BTree *tree = btree_initialize(10);

  assert_that(tree, is_not_equal_to(NULL));
  assert_that(tree->data, is_equal_to(10));
}

Ensure(height_returns_height_of_tree) {
  BTree *tree = NULL;

  int n = 10;
  for (int i = 0; i < n; ++i)
    tree = btree_insert(tree, i);

  assert_that(btree_height(tree), is_equal_to(n));
}

Ensure(tree_with_k_leaves_has_height_of_log_k) {
  for (int k = 0; k < 500; ++k)
    assert_that(btree_height(btree_generate(k)) >= log2(k), is_equal_to(true));
}

TestSuite *btree_tests() {
  TestSuite *x = create_test_suite();

  add_test(x, initialize_returns_new_btree);
  add_test(x, height_returns_height_of_tree);
  add_test(x, tree_with_k_leaves_has_height_of_log_k);

  return x;
}

#include "binary_tree.h"
#include <cgreen/cgreen.h>
#include <string.h>

int visited[256];
int visited_count;

Describe(BinaryTree);
BeforeEach(BinaryTree) {
  memset(visited, 0, sizeof(visited));
  visited_count = 0;
}
AfterEach(BinaryTree) {}

void visitor(Node *node) {
  visited[visited_count] = node->data;
  visited_count++;
}

Ensure(BinaryTree, when_traversing_in_preorder_when_the_tree_is_empty) {
  preorder_traversal(NULL, visitor);

  assert_that(visited_count, is_equal_to(0));
}

Ensure(BinaryTree, when_traversing_in_preorder_when_the_tree_has_a_single_node) {
  Node *node = initialize(100);

  preorder_traversal(node, visitor);

  assert_that(visited_count, is_equal_to(1));
  assert_that(visited[0], is_equal_to(100));
}

Ensure(BinaryTree, when_traversing_in_preorder_when_the_tree_has_a_left_node) {
  Node *node = initialize(100);
  node->left = initialize(200);

  preorder_traversal(node, visitor);

  assert_that(visited_count, is_equal_to(2));
  assert_that(visited[0], is_equal_to(100));
  assert_that(visited[1], is_equal_to(200));
}

Ensure(BinaryTree, when_traversing_in_preorder_when_the_tree_has_a_right_node) {
  Node *node = initialize(100);
  node->right = initialize(300);

  preorder_traversal(node, visitor);

  assert_that(visited_count, is_equal_to(2));
  assert_that(visited[0], is_equal_to(100));
  assert_that(visited[1], is_equal_to(300));
}

Ensure(BinaryTree, when_traversing_in_preorder_when_the_tree_has_a_left_and_right_node) {
  Node *node = initialize(100);
  node->left = initialize(200);
  node->right = initialize(300);

  preorder_traversal(node, visitor);

  assert_that(visited_count, is_equal_to(3));
  assert_that(visited[0], is_equal_to(100));
  assert_that(visited[1], is_equal_to(200));
  assert_that(visited[2], is_equal_to(300));
}

Ensure(BinaryTree, when_traversing_in_preorder_when_the_tree_has_multiple_levels) {
  Node *node = initialize(100);
  node->left = initialize(200);
  node->right = initialize(300);

  node->left->left = initialize(400);
  node->left->right = initialize(500);

  preorder_traversal(node, visitor);

  assert_that(visited_count, is_equal_to(5));
  assert_that(visited[0], is_equal_to(100));
  assert_that(visited[1], is_equal_to(200));
  assert_that(visited[2], is_equal_to(400));
  assert_that(visited[3], is_equal_to(500));
  assert_that(visited[4], is_equal_to(300));
}

TestSuite *binary_tree_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, BinaryTree, when_traversing_in_preorder_when_the_tree_is_empty);
  add_test_with_context(suite, BinaryTree, when_traversing_in_preorder_when_the_tree_has_a_single_node);
  add_test_with_context(suite, BinaryTree, when_traversing_in_preorder_when_the_tree_has_a_left_node);
  add_test_with_context(suite, BinaryTree, when_traversing_in_preorder_when_the_tree_has_a_right_node);

  return suite;
}

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, binary_tree_tests());
  return run_test_suite(suite, create_text_reporter());
}

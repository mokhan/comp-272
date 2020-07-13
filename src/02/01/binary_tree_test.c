#include "binary_tree.h"
#include <cgreen/cgreen.h>
#include <string.h>

int visited[32];
Node *nodes[32];
int visited_count;

Describe(BinaryTree);
BeforeEach(BinaryTree) {
  memset(visited, 0, sizeof(visited));
  memset(nodes, 0, sizeof(nodes));
  visited_count = 0;
}
AfterEach(BinaryTree) {}

void visitor(Node *node) {
  visited[visited_count] = node->data;
  nodes[visited_count] = node;
  visited_count++;
}

Node *next(Node *self, Node *x, enum Traversal traversal) {
  traverse(self, visitor, traversal);

  for (int i = 0; i < visited_count; i++)
    if (nodes[i] == x)
      return nodes[i + 1];
  return NULL;
}

Node *preorder_next(Node *self, Node *x) {
  return next(self, x, PREORDER);
}

Node *inorder_next(Node *self, Node *x) {
  return next(self, x, INORDER);
}

Node *postorder_next(Node *self, Node *x) {
  return next(self, x, POSTORDER);
}

Ensure(BinaryTree, when_traversing_in_preorder_when_the_tree_is_empty) {
  traverse(NULL, visitor, PREORDER);

  assert_that(visited_count, is_equal_to(0));
}

Ensure(BinaryTree,
       when_traversing_in_preorder_when_the_tree_has_a_single_node) {
  Node *node = initialize(100);

  traverse(node, visitor, PREORDER);

  assert_that(visited_count, is_equal_to(1));
  assert_that(visited[0], is_equal_to(100));
  destroy(node);
}

Ensure(BinaryTree, when_traversing_in_preorder_when_the_tree_has_a_left_node) {
  Node *node = initialize(100);
  node->left = initialize(200);

  traverse(node, visitor, PREORDER);

  assert_that(visited_count, is_equal_to(2));
  assert_that(visited[0], is_equal_to(100));
  assert_that(visited[1], is_equal_to(200));
  destroy(node);
}

Ensure(BinaryTree, when_traversing_in_preorder_when_the_tree_has_a_right_node) {
  Node *node = initialize(100);
  node->right = initialize(300);

  traverse(node, visitor, PREORDER);

  assert_that(visited_count, is_equal_to(2));
  assert_that(visited[0], is_equal_to(100));
  assert_that(visited[1], is_equal_to(300));
  destroy(node);
}

Ensure(BinaryTree,
       when_traversing_in_preorder_when_the_tree_has_a_left_and_right_node) {
  Node *node = initialize(100);
  node->left = initialize(200);
  node->right = initialize(300);

  traverse(node, visitor, PREORDER);

  assert_that(visited_count, is_equal_to(3));
  assert_that(visited[0], is_equal_to(100));
  assert_that(visited[1], is_equal_to(200));
  assert_that(visited[2], is_equal_to(300));
  destroy(node);
}

Ensure(BinaryTree,
       when_traversing_in_preorder_when_the_tree_has_multiple_levels) {
  Node *node = initialize(100);
  node->left = initialize(200);
  node->right = initialize(300);

  node->left->left = initialize(400);
  node->left->right = initialize(500);

  traverse(node, visitor, PREORDER);

  assert_that(visited_count, is_equal_to(5));
  assert_that(visited[0], is_equal_to(100));
  assert_that(visited[1], is_equal_to(200));
  assert_that(visited[2], is_equal_to(400));
  assert_that(visited[3], is_equal_to(500));
  assert_that(visited[4], is_equal_to(300));
  destroy(node);
}

Ensure(BinaryTree, when_traversing_in_postorder_when_the_tree_is_empty) {
  traverse(NULL, visitor, POSTORDER);

  assert_that(visited_count, is_equal_to(0));
}

Ensure(BinaryTree,
       when_traversing_in_postorder_when_the_tree_has_a_single_node) {
  Node *node = initialize(100);

  traverse(node, visitor, POSTORDER);

  assert_that(visited_count, is_equal_to(1));
  assert_that(visited[0], is_equal_to(100));
  destroy(node);
}

Ensure(BinaryTree, when_traversing_in_postorder_when_the_tree_has_a_left_node) {
  Node *node = initialize(100);
  node->left = initialize(200);

  traverse(node, visitor, POSTORDER);

  assert_that(visited_count, is_equal_to(2));
  assert_that(visited[0], is_equal_to(200));
  assert_that(visited[1], is_equal_to(100));
  destroy(node);
}

Ensure(BinaryTree,
       when_traversing_in_postorder_when_the_tree_has_a_right_node) {
  Node *node = initialize(100);
  node->right = initialize(300);

  traverse(node, visitor, POSTORDER);

  assert_that(visited_count, is_equal_to(2));
  assert_that(visited[0], is_equal_to(300));
  assert_that(visited[1], is_equal_to(100));
  destroy(node);
}

Ensure(BinaryTree,
       when_traversing_in_postorder_when_the_tree_has_a_left_and_right_node) {
  Node *node = initialize(100);
  node->left = initialize(200);
  node->right = initialize(300);

  traverse(node, visitor, POSTORDER);

  assert_that(visited_count, is_equal_to(3));
  assert_that(visited[0], is_equal_to(200));
  assert_that(visited[1], is_equal_to(300));
  assert_that(visited[2], is_equal_to(100));
  destroy(node);
}

Ensure(BinaryTree,
       when_traversing_in_postorder_when_the_tree_has_multiple_levels) {
  Node *node = initialize(100);
  node->left = initialize(200);
  node->right = initialize(300);

  node->left->left = initialize(400);
  node->left->right = initialize(500);

  traverse(node, visitor, POSTORDER);

  assert_that(visited_count, is_equal_to(5));
  assert_that(visited[0], is_equal_to(400));
  assert_that(visited[1], is_equal_to(500));
  assert_that(visited[2], is_equal_to(200));
  assert_that(visited[3], is_equal_to(300));
  assert_that(visited[4], is_equal_to(100));
  destroy(node);
}

Ensure(BinaryTree, when_traversing_inorder_when_the_tree_is_empty) {
  traverse(NULL, visitor, INORDER);

  assert_that(visited_count, is_equal_to(0));
}

Ensure(BinaryTree, when_traversing_inorder_when_the_tree_has_a_single_node) {
  Node *node = initialize(100);

  traverse(node, visitor, INORDER);

  assert_that(visited_count, is_equal_to(1));
  assert_that(visited[0], is_equal_to(100));
  destroy(node);
}

Ensure(BinaryTree, when_traversing_inorder_when_the_tree_has_a_left_node) {
  Node *node = initialize(100);
  node->left = initialize(200);

  traverse(node, visitor, INORDER);

  assert_that(visited_count, is_equal_to(2));
  assert_that(visited[0], is_equal_to(200));
  assert_that(visited[1], is_equal_to(100));
  destroy(node);
}

Ensure(BinaryTree, when_traversing_inorder_when_the_tree_has_a_right_node) {
  Node *node = initialize(100);
  node->right = initialize(300);

  traverse(node, visitor, INORDER);

  assert_that(visited_count, is_equal_to(2));
  assert_that(visited[0], is_equal_to(100));
  assert_that(visited[1], is_equal_to(300));
  destroy(node);
}

Ensure(BinaryTree,
       when_traversing_inorder_when_the_tree_has_a_left_and_right_node) {
  Node *node = initialize(100);
  node->left = initialize(200);
  node->right = initialize(300);

  traverse(node, visitor, INORDER);

  assert_that(visited_count, is_equal_to(3));
  assert_that(visited[0], is_equal_to(200));
  assert_that(visited[1], is_equal_to(100));
  assert_that(visited[2], is_equal_to(300));
  destroy(node);
}

Ensure(BinaryTree, when_traversing_inorder_when_the_tree_has_multiple_levels) {
  Node *node = initialize(100);
  node->left = initialize(200);
  node->right = initialize(300);

  node->left->left = initialize(400);
  node->left->right = initialize(500);

  traverse(node, visitor, INORDER);

  assert_that(visited_count, is_equal_to(5));
  assert_that(visited[0], is_equal_to(400));
  assert_that(visited[1], is_equal_to(200));
  assert_that(visited[2], is_equal_to(500));
  assert_that(visited[3], is_equal_to(100));
  assert_that(visited[4], is_equal_to(300));
  destroy(node);
}

Ensure(BinaryTree, when_finding_the_next_node_in_a_preorder_traversal) {
  Node *a = initialize(100);
  Node *b = initialize(200);
  Node *c = initialize(300);
  Node *d = initialize(400);
  Node *e = initialize(500);

  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;

  assert_that(preorder_next(a, a), is_equal_to(b));
  assert_that(preorder_next(a, b), is_equal_to(d));
  assert_that(preorder_next(a, c), is_equal_to(a));
  assert_that(preorder_next(a, d), is_equal_to(e));
  assert_that(preorder_next(a, e), is_equal_to(c));

  destroy(a);
}

Ensure(BinaryTree, when_finding_the_next_node_in_a_inorder_traversal) {
  Node *a = initialize(100);
  Node *b = initialize(200);
  Node *c = initialize(300);
  Node *d = initialize(400);
  Node *e = initialize(500);

  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;

  assert_that(inorder_next(a, a), is_equal_to(c));
  assert_that(inorder_next(a, b), is_equal_to(e));
  assert_that(inorder_next(a, c), is_equal_to(d));
  assert_that(inorder_next(a, d), is_equal_to(b));
  assert_that(inorder_next(a, e), is_equal_to(a));

  destroy(a);
}

Ensure(BinaryTree, when_finding_the_next_node_in_a_postorder_traversal) {
  Node *a = initialize(100);
  Node *b = initialize(200);
  Node *c = initialize(300);
  Node *d = initialize(400);
  Node *e = initialize(500);

  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;

  assert_that(postorder_next(a, a), is_equal_to(NULL));
  assert_that(postorder_next(a, b), is_equal_to(c));
  assert_that(postorder_next(a, c), is_equal_to(a));
  assert_that(postorder_next(a, d), is_equal_to(e));
  assert_that(postorder_next(a, e), is_equal_to(b));

  destroy(a);
}


TestSuite *binary_tree_tests() {
  TestSuite *suite = create_test_suite();

  add_test_with_context(suite, BinaryTree, when_traversing_in_preorder_when_the_tree_is_empty);
  add_test_with_context(suite, BinaryTree, when_traversing_in_preorder_when_the_tree_has_a_single_node);
  add_test_with_context(suite, BinaryTree, when_traversing_in_preorder_when_the_tree_has_a_left_node);
  add_test_with_context(suite, BinaryTree, when_traversing_in_preorder_when_the_tree_has_a_right_node);
  add_test_with_context(suite, BinaryTree, when_traversing_in_preorder_when_the_tree_has_a_left_and_right_node);
  add_test_with_context(suite, BinaryTree, when_traversing_in_preorder_when_the_tree_has_multiple_levels);

  add_test_with_context(suite, BinaryTree, when_traversing_in_postorder_when_the_tree_is_empty);
  add_test_with_context(suite, BinaryTree, when_traversing_in_postorder_when_the_tree_has_a_single_node);
  add_test_with_context(suite, BinaryTree, when_traversing_in_postorder_when_the_tree_has_a_left_node);
  add_test_with_context(suite, BinaryTree, when_traversing_in_postorder_when_the_tree_has_a_right_node);
  add_test_with_context(suite, BinaryTree, when_traversing_in_postorder_when_the_tree_has_a_left_and_right_node);
  add_test_with_context(suite, BinaryTree, when_traversing_in_postorder_when_the_tree_has_multiple_levels);

  add_test_with_context(suite, BinaryTree, when_traversing_inorder_when_the_tree_is_empty);
  add_test_with_context(suite, BinaryTree, when_traversing_inorder_when_the_tree_has_a_single_node);
  add_test_with_context(suite, BinaryTree, when_traversing_inorder_when_the_tree_has_a_left_node);
  add_test_with_context(suite, BinaryTree, when_traversing_inorder_when_the_tree_has_a_right_node);
  add_test_with_context(suite, BinaryTree, when_traversing_inorder_when_the_tree_has_a_left_and_right_node);
  add_test_with_context(suite, BinaryTree, when_traversing_inorder_when_the_tree_has_multiple_levels);

  add_test_with_context(suite, BinaryTree, when_finding_the_next_node_in_a_preorder_traversal);
  add_test_with_context(suite, BinaryTree, when_finding_the_next_node_in_a_inorder_traversal);
  add_test_with_context(suite, BinaryTree, when_finding_the_next_node_in_a_postorder_traversal);

  return suite;
}

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_suite(suite, binary_tree_tests());
  return run_test_suite(suite, create_text_reporter());
}

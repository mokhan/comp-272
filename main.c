#include <cgreen/cgreen.h>

TestSuite *words_tests();
TestSuite *priority_queue_tests();
TestSuite *stack_tests();
TestSuite *swap_singly_linked_list_tests();
TestSuite *swap_doubly_linked_list_tests();
TestSuite *min_stack_tests();

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();

  add_suite(suite, words_tests());
  add_suite(suite, priority_queue_tests());
  add_suite(suite, stack_tests());
  add_suite(suite, swap_singly_linked_list_tests());
  add_suite(suite, swap_doubly_linked_list_tests());
  add_suite(suite, min_stack_tests());

  if (argc > 1)
    return run_single_test(suite, argv[1], create_text_reporter());
  return run_test_suite(suite, create_text_reporter());
}

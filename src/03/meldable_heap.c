#include "meldable_heap.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Compares two integers and returns -1, 0, 1.
 * If a is equal to b then 0 is returned.
 * If a is greater than b then 1 is returned.
 * If a is less than b then -1 is returned.
 *
 * @param a An integer
 * @param b Another integer
 * @return Returns 0, 1, or -1.
 */
static int compare(int a, int b) { return (a < b) ? -1 : ((a > b) ? 1 : 0); }

/**
 * Print a visual representation of a heap.
 *
 * @param heap The subtree to print
 * @param level The level in the heap that this subtree is in
 */
static void print_tree(MeldableHeap *heap, int level) {
  for (int i = 0; i < level; i++)
    printf(" ");

  if (heap) {
    printf("(%d)\n", heap->value);

    if (!heap->left && !heap->right)
      return;
    print_tree(heap->left, level + 1);
    print_tree(heap->right, level + 1);
  } else {
    printf("( )\n");
  }
}

/**
 * Initializes an instance of an meldable heap.
 *
 * @param value The value to assign to the new node in the heap.
 * @return Returns the new heap node instance.
 */
MeldableHeap *meldable_heap_initialize(int value) {
  MeldableHeap *heap = malloc(sizeof(MeldableHeap));
  heap->left = NULL;
  heap->right = NULL;
  heap->parent = NULL;
  heap->value = value;
  return heap;
};

/**
 * Adds a new value into a heap.
 *
 * @param heap The subtree to attempt to insert a new value into.
 * @param value The value to insert.
 * @return Returns the new root of the subtree.
 */
MeldableHeap *meldable_heap_add(MeldableHeap *heap, int value) {
  MeldableHeap *root =
      meldable_heap_merge(meldable_heap_initialize(value), heap);
  root->parent = NULL;
  return root;
}

/**
 * Merges to meldable heaps into a single heap and returns the
 * root of the new heap.
 *
 * @param h1 A heap
 * @param h2 Another heap
 * @return Returns the merged heap
 */
MeldableHeap *meldable_heap_merge(MeldableHeap *h1, MeldableHeap *h2) {
  if (h1 == NULL)
    return h2;
  if (h2 == NULL)
    return h1;

  if (compare(h2->value, h1->value) < 0)
    return meldable_heap_merge(h2, h1);

  if (rand() % 2 == 0) {
    h1->left = meldable_heap_merge(h1->left, h2);
    h1->left->parent = h1;
  } else {
    h1->right = meldable_heap_merge(h1->right, h2);
    h1->right->parent = h1;
  }
  return h1;
}

/**
 * Prints a visual inspection of
 * a heap for debugging purposes to stdout.
 *
 * @param heap The heap to visualize
 */
void meldable_heap_inspect(MeldableHeap *heap) { print_tree(heap, 0); }

/**
 * Removes a value from a meldable heap.
 *
 * @param heap The subtree to remove
 */
void meldable_heap_remove(MeldableHeap *heap) {
  MeldableHeap *replacement = meldable_heap_merge(heap->left, heap->right);

  if (replacement)
    replacement->parent = heap->parent;

  if (!heap->parent)
    return;

  if (heap->parent->left == heap)
    heap->parent->left = replacement;
  else
    heap->parent->right = replacement;
}

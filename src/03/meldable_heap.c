#include "meldable_heap.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static int compare(int a, int b)
{
  return (a < b) ? -1 : ((a > b) ? 1 : 0);
}

static void print_tree(MeldableHeap *heap, int level) {
  for (int i = 0; i < level; i++)
    printf(" ");

  if (heap) {
    printf("(%d)\n", heap->value);

    if (!heap->left && !heap->right)
      return;
    print_tree(heap->left, level + 1);
    print_tree(heap->right, level + 1);
  }
  else {
    printf("( )\n");
  }
}


MeldableHeap *meldable_heap_initialize(int value) {
  MeldableHeap *heap = malloc(sizeof(MeldableHeap));
  heap->left = NULL;
  heap->right = NULL;
  heap->parent = NULL;
  heap->value = value;
  return heap;
};

MeldableHeap *meldable_heap_add(MeldableHeap *heap, int value) {
  MeldableHeap *root = meldable_heap_merge(meldable_heap_initialize(value), heap);
  root->parent = NULL;
  return root;
}

MeldableHeap *meldable_heap_merge(MeldableHeap *h1, MeldableHeap* h2) {
  if (h1 == NULL) return h2;
  if (h2 == NULL) return h1;

  if (compare(h2->value, h1->value) < 0)
    return meldable_heap_merge(h2, h1);

  if (rand() % 2 == 0) {
    h1->left = meldable_heap_merge(h1->left, h2);
    h1->left->parent = h1;
  }
  else {
    h1->right = meldable_heap_merge(h1->right, h2);
    h1->right->parent = h1;
  }
  return h1;
}

void meldable_heap_inspect(MeldableHeap *heap)
{
  print_tree(heap, 0);
}

void meldable_heap_remove(MeldableHeap *heap)
{
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

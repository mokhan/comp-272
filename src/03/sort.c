#include <stdio.h>
#include <stdlib.h>

/**
 * Prints a visual dump of an array of
 * items to stdout out for debugging.
 *
 * @param items The items to inspect
 * @param n The total # of items in the array.
 */
static void dump(int *items, int n) {
  printf("[");
  for (int i = 0; i < n; ++i)
    printf("%d,", items[i]);
  printf("]\n");
}

/**
 * Merges two subsequences of an array.
 *
 * @params items A pointer to the start of an array of items
 * @param min The starting index of the left sub sequence.
 * @param mid The starting index of the right sub sequence.
 * @param max The ending index of the right sub sequence.
 */
static void _merge(int *items, int min, int mid, int max) {
  int length = (max - min) + 1;
  int tmp[length];
  int j = min, k = mid;

  for (int i = 0; i < length; i++) {
    if (j < mid && k <= max)
      if (items[j] < items[k])
        tmp[i] = items[j++];
      else
        tmp[i] = items[k++];
    else if (j >= mid)
      tmp[i] = items[k++];
    else
      tmp[i] = items[j++];
  }

  for (int i = 0; i < length; i++)
    items[min + i] = tmp[i];
}

/**
 * Performs a recursive merge sort of items in an array.
 *
 * @param items An array of integers.
 * @param min The starting index of a subsequence to sort
 * @param max The ending index of a subsequence to sort
 */
static void _merge_sort(int *items, int min, int max) {
  if (min >= max)
    return;

  int mid = min + (max - min) / 2;
  _merge_sort(items, min, mid);
  _merge_sort(items, mid + 1, max);
  _merge(items, min, mid + 1, max);
}

/**
 * Partitions a sequence into two subsequences.
 *
 * @param items An array of integers to partition
 * @param min The starting index of the sequence to partition
 * @param max The ending index of the sequence to partition
 * @return Returns the index that can be used as the partition point for the
 * sequence.
 */
static int partition(int *items, int min, int max) {
  int pivot = items[max];
  int index = min - 1;
  int tmp;

  for (int j = min; j < max; j++) {
    if (items[j] < pivot) {
      index++;
      tmp = items[index];
      items[index] = items[j];
      items[j] = tmp;
    }
  }
  tmp = items[index + 1];
  items[index + 1] = items[max];
  items[max] = tmp;

  return index + 1;
}

/**
 * Performs a recursive quick sort on an array of items.
 *
 * @param items An array of integers
 * @param min The starting index of a subsequence to sort
 * @param max The ending index of a subsequence to sort
 */
static void _quick_sort(int *items, int min, int max) {
  if (min >= max)
    return;

  int index = partition(items, min, max);
  _quick_sort(items, min, index - 1);
  _quick_sort(items, index + 1, max);
}

/**
 * Performs a merge sort on an array of integers.
 *
 * @param items An array of integers
 * @param length The # of items in the array of integers
 */
void merge_sort(int *items, int length) {
  if (!items || length <= 0)
    return;

  _merge_sort(items, 0, length - 1);
}

/**
 * Performs a quick sort on an array of integers.
 *
 * @param items An array of integers
 * @param length The # of items in the array of integers
 */
void quick_sort(int *items, int length) {
  if (!items || length <= 0)
    return;

  _quick_sort(items, 0, length - 1);
}

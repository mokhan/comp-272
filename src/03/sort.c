#include <stdio.h>
#include <stdlib.h>

static void dump(int *items, int n) {
  printf("[");
  for (int i = 0; i < n; ++i)
    printf("%d,", items[i]);
  printf("]\n");
}

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

static void _merge_sort(int *items, int min, int max) {
  if (min >= max)
    return;

  int mid = min + (max - min) / 2;
  _merge_sort(items, min, mid);
  _merge_sort(items, mid + 1, max);
  _merge(items, min, mid + 1, max);
}

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

static void _quick_sort(int *items, int min, int max) {
  if (min >= max)
    return;

  int index = partition(items, min, max);
  _quick_sort(items, min, index - 1);
  _quick_sort(items, index + 1, max);
}

void merge_sort(int *items, int length) {
  if (!items || length <= 0)
    return;

  _merge_sort(items, 0, length - 1);
}

void quick_sort(int *items, int length) {
  if (!items || length <= 0)
    return;

  _quick_sort(items, 0, length - 1);
}

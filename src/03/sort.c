#include <stdio.h>

void _merge(int *items, int min, int pivot, int max)
{
  if (items[min] > items[pivot]) {
    int tmp[max-min];
    for (int i = pivot; i < max; i++)
      tmp[i] = items[i];
    for (int i = min; i < pivot; i++)
      tmp[max + i] = items[i];
    for (int i = 0; i < max-min; i++)
      items[min+i] = tmp[i];
  }
}

void _merge_sort(int *items, int min, int max)
{
  if (!items || max == min)
    return;

  int pivot = ((max - min) / 2) + min;
  _merge_sort(items, min, pivot);
  _merge_sort(items, pivot + 1, max);
  _merge(items, min, pivot + 1, max);
}

void merge_sort(int *items, int length) {
  if (!items || length <= 0)
    return;

  _merge_sort(items, 0, length - 1);
}

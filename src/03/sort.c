#include <stdio.h>

void _merge(int *items, int min, int pivot, int max)
{
  if (items[min] > items[pivot]) {
    int length = (max-min) + 1;
    int tmp[length];

    for (int i = pivot; i <= max; i++)
      tmp[i - pivot] = items[i];

    for (int i = min; i < pivot; i++)
      tmp[i + pivot - min] = items[i];

    for (int i = 0; i < length; i++)
      items[min+i] = tmp[i];
  }
}

void _merge_sort(int *items, int min, int max)
{
  if (!items || max == min)
    return;

  int pivot = (min + max) / 2;
  _merge_sort(items, min, pivot);
  _merge_sort(items, pivot + 1, max);
  _merge(items, min, pivot + 1, max);
}

void merge_sort(int *items, int length) {
  if (!items || length <= 0)
    return;

  _merge_sort(items, 0, length - 1);
}

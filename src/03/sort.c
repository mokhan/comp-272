#include <stdio.h>

void _merge(int *items, int min, int mid, int max)
{
  int length = (max-min) + 1;
  int tmp[length];
  int j = min, k = mid;

  for (int i = 0; i < length; i++) {
    if (j < mid && k <= max)
      if (items[j] < items[k])
        tmp[i] = items[j++];
      else
        tmp[i] = items[k++];
    else
      if (j >= mid)
        tmp[i] = items[k++];
      else
        tmp[i] = items[j++];
  }

  for (int i = 0; i < length; i++)
    items[min+i] = tmp[i];
}

void _merge_sort(int *items, int min, int max)
{
  if (min >= max)
    return;

  int mid = min + (max - min) / 2;
  _merge_sort(items, min, mid);
  _merge_sort(items, mid + 1, max);
  _merge(items, min, mid + 1, max);
}

void merge_sort(int *items, int length) {
  if (!items || length <= 0)
    return;

  _merge_sort(items, 0, length - 1);
}

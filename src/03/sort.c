#include <stdio.h>

void _merge(int *items, int min, int mid, int max)
{
  int length = (max-min) + 1;
  int tmp[length];

  int j = 0, k = 0;
  for (int i = 0; i < length; i++) {
    if (items[min+j] < items[mid+k]) {
      tmp[i] = items[min+j];
      j++;
    } else {
      tmp[i] = items[mid+k];
      k++;
    }
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

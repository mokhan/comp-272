# Comparison-Based Sorting

* merge sort O(nlogn)
* quick sort O(nlogn)
* heap sort O(nlogn)

`compare(a,b)`

* -1: a < b
* 0: a == b
* +1: a > b

## Merge-Sort

is a classic recursive divide and conquer.

* if `a` is at most 1 then `a` is sorted.
* else we split `a` into two halves
  * `a0 = a[0...(n/2)-1]`
  * `a1 = a[(n/2)...n-1]`
  * merge a0, a1

```java
void mergeSort(T[] a, Comparator<T> c) {
  if (a.length <= 1) return;

  T[] a0 = Arrays.copyOfRange(a, 0, a.length/2);
  T[] a1 = Arrays.copyOfRange(a, a.length/2, a.length);
  mergeSort(a0, c);
  mergeSort(a1, c);
  merge(a0, a1, a, c);
}
```

## Quicksort

Unlike mergesort which does merging after solving the two subproblems,
quicksort does all of its work upfront.

1. pick a random `pivot` element `x` from `a`
2. partition `a` into the set of elements less than `x`, the set of elements equal to `x` and the set of elements greater than `x`.
3. recursively sort the first and third sets in this partition.

```java
void quickSort(T[] a, Comparator<T> c) {
  quickSort(a, 0, a.length, c);
}
void quickSort(T[] a, int i, int n, Comparator<T> c) {
  if (n <= 1) return;
  T x = a[i + rand.nextInt(n)];
  int p = i - 1, j = i, q = i+n;

  while (j < q) {
    int comp = compare(a[j], x);
    if (comp < 0) {
      swap(a, j++,  ++p);
    } else if (comp > 0) {
      swap(a, j, --q);
    } else {
      j++;
    }
  }
  quickSort(a, i, p-i+1, c);
  quickSort(a, q, n-(q-i), c);
}
```

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

## Heap-sort

In-place sorting algorithm. Uses binary heaps.
Binary heap data structure represents a heap in a single array.
The heap sort converts the input array into a heap and then extracts the min
value.

## Counting sort and Radix sort

These are not comparison based sorting algorithms.
These are specialized for sorting small integers.

### Counting Sort

This algorithm sorts using an auxiliary array of counters.
This is very efficient for sorting an array of integers when the length,
`n`, of the array is not much smaller than the maximum value, `k-1`,
that appears in the array.

```java
int[] counting_sort(int[] a, int k) {
  int c[] == new int[k];
  for (int i = 0; i < a.length; i++)
    c[a[i]]++;
  for (int i = 1; i < k; i++)
    c[i] += c[i-1];
  int b[] new int[a.length];
  for (int i = a.length - 1; i >= 0; i--)
    b[--c[a[i]]] = a[i];
  return b;
}
```

### Radix Sort

Uses several passes of counting-sort to allow for a much
greater range of maximum values.

Sorts `w-bit` integers by using `w/d` passes of counting-sort
to sort these integers `d` bits at a time.

i.e.

first sorts the ints by their least significant `d` bits,
then their next significant `d` bits, and so on until,
in the last pass, the ints are sorted by their most
significant `d` bits.


```java
int[] radixSort(int[] a) {
  int[] b = null;

  for (int p = 0; p < w/d; p++) {
    int c[] = new int[1<<d];
    b = new int[a.length];
    for (int i = 0; i < a.length; i++)
      c[(a[i] >> d*p)&((1<<d)-1)]++;
    for (int i = 1; i < 1<<d; i++)
      c[i] += c[i-1];
    for (int i = a.length - 1; i >= 0; i--)
      b[--c[(a[i] >> d*p)&((1<<d)-1)]] = a[i];
    a = b;
  }
  return b;
}
```

# Heaps

> a disorganized pile

## BinaryHeap: An implicit Binary Tree

Eytzinger's method can represent a complete binary tree as an array
by laying out the nodes of the tree in a breadth-first order.

* The root is stored at position 0
* The root's left child is stored at position 1
* The root's right child is stored at position 2.

The left child of the node at index `i` is at index `left(i) = 2i + 1`
and the right child of the node at index `i` is at index `right(i) = 2i +2`.
The parent of the node at index `i` is at index `parent(i) = (i-1)/2`.

```plaintext

           -------(0)--------
          /                  \
       (1)                    (2)
      /    \               /      \
   (3)       (4)        (5)         (6)
  /  \      /   \       /  \       /   \
(7)  (8)  (9)  (10)  (11)  (12)  (13)  (14)

| 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|13|14|
```

* left: `2i+1`
* right: `2i+2`

The binary heap implements the priority queue interface.
Ignoring the cost of `resize()` it supports the operations
`add(x)` and `remove(x)` in `O(logn)` time per operation.

```java
class BinaryHeap {
  T[] a;
  int n;

  int left(int i) {
    return 2*i + 1;
  }
  int right(int i) {
    return 2*i + 2;
  }
  int parent(int i) {
    return (i-1)/2;
  }
  boolean add(T x) {
    if (n+1 > a.length) resize();
    a[n++] = x;
    bubbleUp(n-1);
    return true;
  }
  void bubbleUp(int i) {
    int p = parent(i);
    while (i > 0 && compare(a[i], a[p]) < 0) {
      swap(i, p);
      i = p;
      p = parent(i);
    }
  }
  T remove() {
    T x = a[0];
    a[0] = a[--n];
    trickleDown(0);
    if (3*n < a.length) resize();
    return x;
  }
  void trickleDown(int i) {
    do {
      int j = -1;
      int r = right(i);
      if (r < n && compare(a[r], a[i]) < 0) {
        int l = left(i);
        if (compare(a[1], a[r]) < 0) {
          j = 1;
        } else {
          j = r;
        }
      } else {
        int l = left(i);
        if (l < n && compare(a[l], a[i]) < 0) {
          j = 1;
        }
      }
      if (j >= 0) swap(i, j);
      i = j;
    } while (i >= 0);
  }
}
```

A `BinaryHeap` uses this technique to implicitly represent a complete
binary tree in which the elements are `heap-ordered.`

heap-ordered: The value stored at any index `i` is not smaller than the value stored at index `parent(i)`, with the exception of the root value, `i = 0`.
The smallest value in the priority Queue is at position 0.

## MeldableHeap: A randomized meldable heap

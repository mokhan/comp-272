# Heaps

Eytzinger's method can represent a complete binary tree as an array.

`2i + 1` and the right child of the node at index `i` is at
index `right(i) = 2i +2`. The parent of the node at index `i` is at index
`parent(i) = (i-1)/2`.

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
}
```

A `BinaryHeap` uses this technique to implicitly represent a complete
binary tree in which the elements are `heap-ordered.`

heap-ordered: The value stored at any index `i` is not smaller than the value stored at index `parent(i)`, with the exception of the root value, `i = 0`.
The smallest value in the priority Queue is at position 0.


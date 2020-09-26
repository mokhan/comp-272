
Implement the `remove(u)` method, that removes the node `u` from a
`MeldableHeap`. This method should run in `O(log n)` expected time.

```java
class MeldableHeap {
  Node<T> merge(Node<T> h1, Node<T> h2) {
    if (h1 == nil) return h2;
    if (h2 == nil) return h1;
    if (compare(h2.x, h1.x) < 0) return merge(h2, h1);

    if (rand.nextBoolean()) {
      h1.left = merge(h1.left, h2);
      h1.left.parent = h1;
    } else {
      h1.right = merge(h1.right, h2);
      h1.right.parent = h1;
    }
    return h1;
  }

  boolean add(T x) {
    Node<T> u = newNode();
    u.x = x;
    r = merge(u, r);
    r.parent = nil;
    n++;
    return true;
  }

  T remove() {
    T x = r.x;
    r = merge(r.left, r.right);
    if (r != nil) r.parent = nil;
    n--;
    return x;
  }
}
```
[Source](https://www.aupress.ca/app/uploads/120226_99Z_Morin_2013-Open_Data_Structures.pdf)

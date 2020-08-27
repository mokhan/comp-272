# 2-4 Trees

* is a rooted tree with the following properties:

* height: all leaves have the same depth
* degree: every internal node has 2, 3 or 4 children.

lemma:

> A 2-4 tree with n leaves has height at most log n.

# Red-Black Trees

* A binary search tree with logarithmic height.

1. tree with `n` values has a height of most 2logn
1. The `add(x)` and `remove(x)` operations on a red-black tree run in `O(logn)` worst case time.
1. The amortized number of rotations performed during an `add(x)` or `remove(x)` operation is constant.

Each node, `u`, has a colour which is either `red` or `black`.

* red: is represented by the value 0.
* black: is represented by the value 1.

A red-black tree implements the SSet interface and supports
operations `add(x)`, `remove(x)`, and `find(x)` in O(logn) worst-case time
per operation.


```java
class Node<T> extends BSTNode<Node<T>, T> {
  byte colour;

  void flipRight(Node<T> u) {
    swapColours(u, u.left);
    rotateRight(u);
  }

  void flipLeft(Node<T> u) {
    swapColours(u, u.right);
    rotateLeft(u);
  }

  boolean add(T x) {
    Node<T> u = newNode(x);
    u.colour = red;
    boolean added = add(u);
    if (added)
      addFixup(u);
    return added;
  }

  void addFixup(Node<T> u) {
    while (u.colour == red) {
      if (u == r) {
        u.colour = black;
        return;
      }
      Node<T> w = u.parent;
      if (w.left.colour == black) {
        flipLeft(w);
        u = w;
        w = u.parent;
      }
      if (w.colour == black)
        return;
      Node<T> g = w.parent;
      if (g.right.colour == black) {
        flipRight(g);
        return;
      } else {
        pushBlack(g);
        u.x = w.x;
        u = w.right;
      }
    }
    splice(w);
    u.colour += w.colour;
    u.parent = w.parent;
    removeFixup(u);
    return true;
  }

  void removeFixup(Node<T> u) {
    while (u.colour > black) {
      if (u == r) {
        u.colour = black;
      } else if (u.parent.left.colour == red) {
        u = removeFixupCase1(u);
      } else if (u == u.parent.left) {
        u = removeFixupCase2(u);
      } else {
        u = removeFixupCase3(u);
      }
    }
    if (u != r) {
      Node<T> w = u.parent;
      if (w.right.colour == red && w.left.colour == black) {
        flipLeft(w);
      }
    }
  }

  Node<T> removeFixupCase3(Node<T> u) {
    Node<T> w = u.parent;
    Node<T> v = w.left;
    pullBlack(w);
    flipRight(w);
    Node<T> q = w.left;
    if (q.colour == red) {
      rotateRight(w);
      flipLeft(v);
      pushBlack(q);
      return q;
    } else {
      if (v.left.colour == red) {
        pushBlack(v);
        return v;
      } else {
        flipLeft(v);
        return w;
      }
    }
  }
}
```

The following properties are satisfied before and after any operation:

* black-height: there are the same # of black nodes on every root to the leaf path. (sum of colours on any root to leaf path is the same.)
* no-red-edge: No two red nodes are adjacent. (except the root, `u.colour + u.parent.colour >= 1`)

The root is black.

# 2-4 Trees

* is a rooted tree with the following properties:

* height: all leaves have the same depth
* degree: every internal node has 2, 3 or 4 children.

lemma:

> A 2-4 tree with n leaves has height at most log n.

# Red-Black Trees

[Lecture Video](https://www.youtube.com/watch?v=JMZkuYa04tY)

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


## AVL Trees

AVL trees are height-balanced.

* height-balanced: at each node `u`, the height of the subtree rooted at `u.left` and the subtree rooted at `u.right` differ by at most one.

AVL trees have a smaller height than red-black trees. The height
balancing can be maintained during `add(x)` and `remove(x)` operations
by walking back up the path to the root and performing a rebalancing
operation at each node `u` where the height of `u`'s left and right subtrees differ by two.

AVL is a self balancing binary search tree in which each node maintains
extra information called a balance factor whose value is either -1, 0, or +1.

The balance factor is determined by calculating the difference
between the height of the left subtree and that of the right subtree of that node.

Balance Factor = (Height of left subtree - height of right subtree) or (height of right subtree - height of left subtree).

The self balancing property of an avl tree is maintained by the balance factory.

E.g.

```plaintext
        (33) 1
      /     \
   (9) -1    (53) -1
  /   \        \
(8) 0 (21) 1    (61) 0
     /
  (11) 0
```

### Operations

* Left Rotate: nodes on the right is transformed into arrangement on the left.
* Right Rotate: nodes on the left are transformed into arrangment on the right.
* Left-Right and Right-Left Rotate: shift left then right.


Left Rotate:

```plaintext
1.
  (x)
    \
    (y)

2.

   (y)
  /
(x)

```

Right Rotate:

```plaintext
1.
  (y)
  /
(x)

2.
(x)
  \
  (y)
```

Left-Right Rotate:

```plaintext
1.
  (z)
  /
(x)
  \
  (y)

2.
    (z)
    /
  (y)
  /
(x)

3.
  (y)
  / \
(x) (z)
```


```plaintext
1.

(z)
  \
   (x)
  /
(y)

2.

(z)
  \
   (y)
     \
     (x)

3.
   (y)
  /   \
(z)   (x)
```

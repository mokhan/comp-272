Illustrate that via AVL single rotation, any binary search tree T1 can be
transformed into another search tree T2 (with the same items).

Left rotation:

```plaintext
  (10)                  (20)
    \                  /    \
    (20)      ->    (10)    (30)
      \
      (30)
```

Right rotation:

```plaintext
     (30)            (20)
     /              /   \
   (20)     -->   (10)  (30)
   /
(10)
```

Left-Right rotation:

```plaintext
   (30)         (20)
   /           /    \
(10)     -> (10)    (30)
   \
   (20)
```

Right-Left rotation:

```plaintext
(10)             (20)
    \            /  \
    (30)  --> (10)  (30)
   /
(20)
```

Give an algorithm to perform this transformation using O(N log N) rotation on average.

See `./../avl_tree.c`.

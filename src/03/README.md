Illustrate that the nodes of any AVL tree T can be
colored "red" and "black" so that T becomes a
red-black tree.

```plaintext
       AVL Tree                   Red-Black Tree
        (20:3)                      (20:b)
        /    \          -->         /    \
    (15:2)    (30:2)           (15:b)    (30:b)
    /    \        \            /   \         \
(10:1) (17:1)     (35:1)  (10:r) (17:r)      (35:r)

* perform pre order traversal
* assign colour of Red/Black node based on height of each AVL node

Step 1:
          (20:b)

Step 2:
          (20:b)
          /
      (15:b)

Step 3:
          (20:b)
          /
      (15:b)
      /
  (10:r)

Step 4:
          (20:b)
          /
      (15:b)
      /   \
  (10:r) (17:r)

Step 5:
          (20:b)
          /     \
      (15:b)    (30:b)
      /   \
  (10:r) (17:r)

Step 6:
          (20:b)
          /    \
      (15:b)    (30:b)
      /   \         \
  (10:r) (17:r)      (35:r)
```

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

See `./avl_tree.c`.

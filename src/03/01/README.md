Illustrate that the nodes of any AVL tree T can be
colored "red" and "black" so that T becomes a
red-black tree.

```plaintext
       AVL Tree                   Red-Black Tree
        (20:3)                      (20:r)
        /    \          -->         /    \
    (15:2)    (30:2)           (15:b)    (30:b)
    /    \        \            /   \         \
(10:1) (17:1)     (35:1)  (10:r) (17:r)      (35:r)

* perform in order traversal
* add node to red/black tree
* assign colour of Red/Black node based on height of AVL node

Step 1:
          (20:r)

Step 2:
          (20:r)
          /
      (15:b)

Step 3:
          (20:r)
          /    \
      (15:b)    (30:b)

Step 4:
          (20:r)
          /    \
      (15:b)    (30:b)
      /
  (10:r)

Step 5:
          (20:r)
          /    \
      (15:b)    (30:b)
      /   \
  (10:r) (17:r)

Step 6:
          (20:r)
          /    \
      (15:b)    (30:b)
      /   \         \
  (10:r) (17:r)      (35:r)
```

```c
RBTree *avl_tree_to_rb_tree(AVLTree *t) {
  if (!t)
    return NULL;

  RBTree *r = rb_tree_initialize_with(t->value, t->height % 2 == 0 ? black : red);
  r->left = avl_tree_to_rb_tree(t->left);
  r->right = avl_tree_to_rb_tree(t->right);
  return r;
}
```

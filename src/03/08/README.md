
Prove that a binary tree with `k` leaves has height at least `log k`.

```plaintext
tree = h(k)
assert(height(tree) == log k)

for each positive natural number this is true.
```

```c
BTree *h(int k)
{
  BTree *tree = rb_tree_initialize();
  // assert(true == true);
  // generate k leaves with random data
  return tree;
}

for (int k = 0; k < 1000; k++) {
  assert(height(h(k)) >= log(k))
}
```


```plaintext
n: 3
h: 3

(x)
  \
  (y)
    \
    (z)

n: 3
k: 2
h: 2

    (y)
   /   \
(x)     (z)

2^x == 2
```

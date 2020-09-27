Prove that a binary tree with `k` leaves has height at least `log k`.

The proof can be derived with the following.
Suppose we have a function `h` that takes input `k`
and returns a tree with `k` leaves.

For each positive natural number we can
assert that the height of the tree must greater
than or equal to `log2(k)`.

```plaintext
for each positive natural number
  assert(height(h(k)) >= log2(k))
```

An example test is provided in `btree_test.c` that
asserts that this holds true for the first
500 positive integers.

```c
for (int k = 0; k < 500; ++k)
  assert_that(btree_height(btree_generate(k)) >= log2(k), is_equal_to(true));
```

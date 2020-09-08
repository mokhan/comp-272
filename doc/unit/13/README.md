# Data Structures for Integers

## BinaryTrie: A digital search tree

encodes a set of `w` bit integers in a binary tree.

* all leaves have depth `w`.
* each integer is encoded as a root-to-leap path.

The path for the int `x` trusn left at level `i` if the `ith`
msb of `x` is a `0` and turns right if it is a `1`.

* 3  -> 0011
* 9  -> 1001
* 12 -> 1100
* 13 -> 1101


```plaintext
                (****)
            /           \
      (0***)             (1***)
      /                  /    \
(00**)             (10**)      (11**)
     \             /           /
     (001*)   (100*)        (110*)
         \         \       /       \
        (3:0011) (9:1001) (12:1100) (13:1101)
```

```java
T find(T x) {
  int i, c = 0, ix = it.intValue(x);
  Node u = r;
  for (i = 0; i < w; i++) {
    c = (ix >>> w-i-1) & 1;
    if (u.child[c] == null) break;
    u = u.child[c];
  }
  if (i == w) return u.x;
  u = (c == 0) ? u.jump : u.jump.child[next];
  return u == dummy ? null : u.x;
}
```

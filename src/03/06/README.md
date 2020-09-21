Why does the method `remove(x)` in the `RedBlackTree` implementation
perform the assignment `u:parent = w:parent?`
Shouldn’t this already be done by the call to `splice(w)`?

```java
boolean remove(T x)
{
  Node<T> u = findLast(x);
  if (u == nil || compare(u.x, x) != 0)
    return false;
  Node<T> w = u.right;
  if (w == nil) {
    w = u;
    u = w.left;
  } else {
    while (w.left != nil)
      w = w.left;
    u.x = w.x;
    u = w.right;
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
```
Source [Open Data Structures](https://www.aupress.ca/app/uploads/120226_99Z_Morin_2013-Open_Data_Structures.pdf)

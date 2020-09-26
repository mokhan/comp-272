Given the graph shown below, answer the following questions:

1. Illustrate the sequence of vertices of this graph visited using depth-first search traversal starting at vertex `g`.
1. Illustrate the sequence of vertices of this graph visited using breadth-first search traversal starting at vertex `b`.
1. Illustrate adjacency list representation and adjacency matrix representation, respectively, for this graph.
  * What are the advantages and disadvantages of those two representations?
1. Describe an algorithm to find in the graph a path illustrated below that goes through every edge exactly once in each direction.


```plaintext
(a)---(b)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(f)/  (g)/--(h)
 |     |   / |    /
 |     |  /  |   /
(i)---(j)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(o)---(p)
```

# Depth First Traversal

Order: g, h, o, p, l, k, n, i, m, j, f, c, d, b, a, e

1. [g]
```plaintext
(a)---(b)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(f)/  (*)/--(h)
 |     |   / |    /
 |     |  /  |   /
(i)---(j)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(o)---(p)
```

2. [g, h]
```plaintext
(a)---(b)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(f)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(i)---(j)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(o)---(p)
```

3. [g, h, o]
```plaintext
(a)---(b)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(f)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(i)---(j)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(*)---(p)
```

4. [g, h, o, p]
```plaintext
(a)---(b)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(f)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(i)---(j)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(*)---(*)
```

5. [g, h, o, p, l]
```plaintext
(a)---(b)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(f)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(i)---(j)/  (k) / (*)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(*)---(*)
```

6. [g, h, o, p, l, k]
```plaintext
(a)---(b)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(f)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(i)---(j)/  (*) / (*)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(*)---(*)
```

7. [g, h, o, p, l, k, n]
```plaintext
(a)---(b)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(f)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(i)---(j)/  (*) / (*)
 | \         | /   |
 |  \        |/    |
(m)  \(*)---(*)---(*)
```

8. [g, h, o, p, l, k, n, i]
```plaintext
(a)---(b)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(f)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(*)---(j)/  (*) / (*)
 | \         | /   |
 |  \        |/    |
(m)  \(*)---(*)---(*)
```

9. [g, h, o, p, l, k, n, i, m]
```plaintext
(a)---(b)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(f)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(*)---(j)/  (*) / (*)
 | \         | /   |
 |  \        |/    |
(*)  \(*)---(*)---(*)
```

10. [g, h, o, p, l, k, n, i, m, j]
```plaintext
(a)---(b)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(f)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(*)---(*)/  (*) / (*)
 | \         | /   |
 |  \        |/    |
(*)  \(*)---(*)---(*)
```

11. [g, h, o, p, l, k, n, i, m, j, f]
```plaintext
(a)---(b)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(*)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(*)---(*)/  (*) / (*)
 | \         | /   |
 |  \        |/    |
(*)  \(*)---(*)---(*)
```

12. [g, h, o, p, l, k, n, i, m, j, f, c]
```plaintext
(a)---(b)---(*)---(d)
 | \       /     /
 |  \     /     /
(e)  \(*)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(*)---(*)/  (*) / (*)
 | \         | /   |
 |  \        |/    |
(*)  \(*)---(*)---(*)
```

13. [g, h, o, p, l, k, n, i, m, j, f, c, d]
```plaintext
(a)---(b)---(*)---(*)
 | \       /     /
 |  \     /     /
(e)  \(*)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(*)---(*)/  (*) / (*)
 | \         | /   |
 |  \        |/    |
(*)  \(*)---(*)---(*)
```

14. [g, h, o, p, l, k, n, i, m, j, f, c, d, b]
```plaintext
(a)---(*)---(*)---(*)
 | \       /     /
 |  \     /     /
(e)  \(*)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(*)---(*)/  (*) / (*)
 | \         | /   |
 |  \        |/    |
(*)  \(*)---(*)---(*)
```

15. [g, h, o, p, l, k, n, i, m, j, f, c, d, b, a]
```plaintext
(*)---(*)---(*)---(*)
 | \       /     /
 |  \     /     /
(e)  \(*)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(*)---(*)/  (*) / (*)
 | \         | /   |
 |  \        |/    |
(*)  \(*)---(*)---(*)
```

16. [g, h, o, p, l, k, n, i, m, j, f, c, d, b, a, e]
```plaintext
(*)---(*)---(*)---(*)
 | \       /     /
 |  \     /     /
(*)  \(*)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(*)---(*)/  (*) / (*)
 | \         | /   |
 |  \        |/    |
(*)  \(*)---(*)---(*)
```

# Breadth First Traversal

Order: [b, a, f, c, e, j, d, i, g, m, n, h, k, o, p, l]

1. [b]
```plaintext
(a)---(*)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(f)/  (g)/--(h)
 |     |   / |    /
 |     |  /  |   /
(i)---(j)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(o)---(p)
```

2. [b, a]
```plaintext
(*)---(*)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(f)/  (g)/--(h)
 |     |   / |    /
 |     |  /  |   /
(i)---(j)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(o)---(p)
```

3. [b, a, f]
```plaintext
(*)---(*)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(*)/  (g)/--(h)
 |     |   / |    /
 |     |  /  |   /
(i)---(j)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(o)---(p)
```

4. [b, a, f, c]
```plaintext
(*)---(*)---(*)---(d)
 | \       /     /
 |  \     /     /
(e)  \(*)/  (g)/--(h)
 |     |   / |    /
 |     |  /  |   /
(i)---(j)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(o)---(p)
```

5. [b, a, f, c, e]
```plaintext
(*)---(*)---(*)---(d)
 | \       /     /
 |  \     /     /
(*)  \(*)/  (g)/--(h)
 |     |   / |    /
 |     |  /  |   /
(i)---(j)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(o)---(p)
```

6. [b, a, f, c, e, j]
```plaintext
(*)---(*)---(*)---(d)
 | \       /     /
 |  \     /     /
(*)  \(*)/  (g)/--(h)
 |     |   / |    /
 |     |  /  |   /
(i)---(*)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(o)---(p)
```

7. [b, a, f, c, e, j, d]
```plaintext
(*)---(*)---(*)---(*)
 | \       /     /
 |  \     /     /
(*)  \(*)/  (g)/--(h)
 |     |   / |    /
 |     |  /  |   /
(i)---(*)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(o)---(p)
```

8. [b, a, f, c, e, j, d, i]
```plaintext
(*)---(*)---(*)---(*)
 | \       /     /
 |  \     /     /
(*)  \(*)/  (g)/--(h)
 |     |   / |    /
 |     |  /  |   /
(*)---(*)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(o)---(p)
```

9. [b, a, f, c, e, j, d, i, g]
```plaintext
(*)---(*)---(*)---(*)
 | \       /     /
 |  \     /     /
(*)  \(*)/  (*)/--(h)
 |     |   / |    /
 |     |  /  |   /
(*)---(*)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(o)---(p)
```

10. [b, a, f, c, e, j, d, i, g, m]
```plaintext
(*)---(*)---(*)---(*)
 | \       /     /
 |  \     /     /
(*)  \(*)/  (*)/--(h)
 |     |   / |    /
 |     |  /  |   /
(*)---(*)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(*)  \(n)---(o)---(p)
```

11. [b, a, f, c, e, j, d, i, g, m, n]
```plaintext
(*)---(*)---(*)---(*)
 | \       /     /
 |  \     /     /
(*)  \(*)/  (*)/--(h)
 |     |   / |    /
 |     |  /  |   /
(*)---(*)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(*)  \(*)---(o)---(p)
```

12. [b, a, f, c, e, j, d, i, g, m, n, h]
```plaintext
(*)---(*)---(*)---(*)
 | \       /     /
 |  \     /     /
(*)  \(*)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(*)---(*)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(*)  \(*)---(o)---(p)
```

13. [b, a, f, c, e, j, d, i, g, m, n, h, k]
```plaintext
(*)---(*)---(*)---(*)
 | \       /     /
 |  \     /     /
(*)  \(*)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(*)---(*)/  (*) / (l)
 | \         | /   |
 |  \        |/    |
(*)  \(*)---(o)---(p)
```

14. [b, a, f, c, e, j, d, i, g, m, n, h, k, o]
```plaintext
(*)---(*)---(*)---(*)
 | \       /     /
 |  \     /     /
(*)  \(*)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(*)---(*)/  (*) / (l)
 | \         | /   |
 |  \        |/    |
(*)  \(*)---(*)---(p)
```

15. [b, a, f, c, e, j, d, i, g, m, n, h, k, o, p]
```plaintext
(*)---(*)---(*)---(*)
 | \       /     /
 |  \     /     /
(*)  \(*)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(*)---(*)/  (*) / (l)
 | \         | /   |
 |  \        |/    |
(*)  \(*)---(*)---(*)
```

16. [b, a, f, c, e, j, d, i, g, m, n, h, k, o, p, l]
```plaintext
(*)---(*)---(*)---(*)
 | \       /     /
 |  \     /     /
(*)  \(*)/  (*)/--(*)
 |     |   / |    /
 |     |  /  |   /
(*)---(*)/  (*) / (*)
 | \         | /   |
 |  \        |/    |
(*)  \(*)---(*)---(*)
```

# Adjacency List

```plaintext
(a)---(b)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(f)/  (g)/--(h)
 |     |   / |    /
 |     |  /  |   /
(i)---(j)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(o)---(p)

(a) -> [b, e, f]
(b) -> [a, f]
(c) -> [b, d, f]
(d) -> [c, g]
(e) -> [a, i]
(f) -> [a, c, j]
(g) -> [d, h, j, k]
(h) -> [g, o]
(i) -> [e, j, m, n]
(j) -> [f, g, i]
(k) -> [g, o]
(l) -> [p]
(m) -> [i]
(n) -> [i, o]
(o) -> [k, n, p]
(p) -> [l, o]
```

Good:

* Space efficient because no space is wasted for edges that do not exist.

Bad:

* A lookup to determine if two vertexes are connected requires a linear time lookup due to the size of the list for a single edge. `O(n)`.

# Adjacency Matrix

```plaintext
(a)---(b)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(f)/  (g)/--(h)
 |     |   / |    /
 |     |  /  |   /
(i)---(j)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(o)---(p)
```

```plaintext
-----------------------------------
| |a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|
|a|0|1|0|0|1|1|0|0|0|0|0|0|0|0|0|0|
|b|1|0|1|0|0|0|0|0|0|0|0|0|0|0|0|0|
|c|0|1|0|1|0|1|0|0|0|0|0|0|0|0|0|0|
|d|0|0|1|0|0|0|1|0|0|0|0|0|0|0|0|0|
|e|1|0|0|0|0|0|0|0|1|0|0|0|0|0|0|0|
|f|1|0|1|0|0|0|0|0|0|1|0|0|0|0|0|0|
|g|0|0|0|1|0|0|0|1|0|1|1|0|0|0|0|0|
|h|0|0|0|0|0|0|1|0|0|0|0|0|0|0|1|0|
|i|0|0|0|0|1|0|0|0|0|1|0|0|1|1|0|0|
|j|0|0|0|0|0|1|1|0|1|0|0|0|0|0|0|0|
|k|0|0|0|0|0|0|1|0|0|0|0|0|0|0|1|0|
|l|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|1|
|m|0|0|0|0|0|0|0|0|1|0|0|0|0|0|0|0|
|n|0|0|0|0|0|0|0|0|1|0|0|0|0|0|1|0|
|o|0|0|0|0|0|0|0|0|0|0|1|0|0|1|0|1|
|p|0|0|0|0|0|0|0|0|0|0|0|1|0|0|1|0|
-----------------------------------
```

Good:

* constant time lookup to see if two vertexes are connected `O(1)`

Bad:

* space inefficient `O(n^2)`


An adjacency matrix might be a better choice when space is less important
than fast lookups. An adjacency list may be a better choice if space is
a higher priority concern than time.

# Traverse Every Edge

To traverse every edge in both directions we can use an adjacency matrix
and iterate through every cell in the matrix. If the cell contains a 1 to
indicate an edge than we know that we can traverse from the edge at
that row and column. Both directions will be represented in different cells
in the matrix.

When we visit each cell in the matrix we can flip the 1 to a 0 to ensure that
we do not revisit a visited edge.

1. Start at any vertex
1. Iterate through list of edges.
1. If the vertex on the other end of the edge has not been visited yet then visit it and loop until all edges are exhausted for the vertex.
1. Remove the edge from the matrix when visiting a node
1. Backtrack to previous vertex, and remove the edge.
1. Visit any edge where you can backtrack safely.

An example of this algorithm can be found in `./matrix.c` with accompanying tests in `./matrix_test.c`.

The graph to traverse is:

```plaintext
(a)---(b)---(c)---(d)
 | \       /     /
 |  \     /     /
(e)  \(f)/  (g)/--(h)
 |     |   / |    /
 |     |  /  |   /
(i)---(j)/  (k) / (l)
 | \         | /   |
 |  \        |/    |
(m)  \(n)---(o)---(p)
```

We can build a matrix that will look like the following:

```bash
| |a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|
|a|0|1|0|0|1|1|0|0|0|0|0|0|0|0|0|0|
|b|1|0|1|0|0|0|0|0|0|0|0|0|0|0|0|0|
|c|0|1|0|1|0|1|0|0|0|0|0|0|0|0|0|0|
|d|0|0|1|0|0|0|1|0|0|0|0|0|0|0|0|0|
|e|1|0|0|0|0|0|0|0|1|0|0|0|0|0|0|0|
|f|1|0|1|0|0|0|0|0|0|1|0|0|0|0|0|0|
|g|0|0|0|1|0|0|0|1|0|1|1|0|0|0|0|0|
|h|0|0|0|0|0|0|1|0|0|0|0|0|0|0|1|0|
|i|0|0|0|0|1|0|0|0|0|1|0|0|1|1|0|0|
|j|0|0|0|0|0|1|1|0|1|0|0|0|0|0|0|0|
|k|0|0|0|0|0|0|1|0|0|0|0|0|0|0|1|0|
|l|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|1|
|m|0|0|0|0|0|0|0|0|1|0|0|0|0|0|0|0|
|n|0|0|0|0|0|0|0|0|1|0|0|0|0|0|1|0|
|o|0|0|0|0|0|0|0|0|0|0|1|0|0|1|0|1|
|p|0|0|0|0|0|0|0|0|0|0|0|1|0|0|1|0|
```

The order of traversal will be:

```plaintext
->(a)->(b)->(c)->(d)->(g)->(h)->(o)->(k)->(g)->(j)->(f)->(a)->(e)->(i)->(m)-
                                                                           |
|---------------------------------------------------------------------------
->(i)->(n)->(o)->(p)->(l)->(p)->(o)->(n)->(i)->(j)->(i)->(e)->(a)->(f)->(c)-
                                                                           |
|---------------------------------------------------------------------------
->(f)->(j)->(g)->(k)->(o)->(h)->(g)->(d)->(c)->(b)->(a)
```

After the traversal the matrix will have zero edges.

```bash
| |a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|
|a|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|b|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|c|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|d|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|e|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|f|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|g|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|h|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|i|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|j|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|k|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|l|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|m|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|n|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|o|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|p|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
```

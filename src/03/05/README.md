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

```plaintext

1. [g]

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

2. [g, h]

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

3. [g, h, o]

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

4. [g, h, o, p]

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

5. [g, h, o, p, l]

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

6. [g, h, o, p, l, k]

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

7. [g, h, o, p, l, k, n]

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

8. [g, h, o, p, l, k, n, i]

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

9. [g, h, o, p, l, k, n, i, m]

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

10. [g, h, o, p, l, k, n, i, m, j]

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

11. [g, h, o, p, l, k, n, i, m, j, f]

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

12. [g, h, o, p, l, k, n, i, m, j, f, c]

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

13. [g, h, o, p, l, k, n, i, m, j, f, c, d]

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

14. [g, h, o, p, l, k, n, i, m, j, f, c, d, b]

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

15. [g, h, o, p, l, k, n, i, m, j, f, c, d, b, a]

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

16. [g, h, o, p, l, k, n, i, m, j, f, c, d, b, a, e]

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

# Adjacency List

# Adjacency Matrix

# Traverse Every Edge

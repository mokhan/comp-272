# Learning Profile for Assignment #3 - Computer Science 272: Data Structures and Algorithms

Name: Mo Khan
Student ID: 3431709

## Question 1
### Problem Statement

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
```

* perform pre order traversal
* assign colour of Red/Black node based on height of each AVL node

```plaintext
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

### Description of the Code

The function `avl_tree_to_rb_tree` provides an
implementation of this. To accomplish this
the code makes two passes down the tree. The
first pass it used to build a clone of the
AVL tree as a Red-Black tree with all nodes coloured
black. The second pass traverses the red-black
tree and applies the appropriate colour to
each node in the function `change_colour`.

If the height of the left subtree is less
than the height of hte right subtree or
the height is odd then the left child is
coloured black otherwise red.

The same is applied to the right subtree.

```c
change_colour(tree->left, left_height < right_height || is_odd(left_height) ? black : red);
change_colour(tree->right, right_height < left_height || is_odd(right_height) ? black : red);
```


## Question 2
### Problem Statement

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

## Question 3
### Problem Statement

Suppose you are given two sequences S1 and S2 of `n` elements, possibly
containing duplicates, on which a total order relation is defined.

1. Describe an efficient algorithm for determining if S1 and S2 contain the same set of elements.

Since S1 and S2 has a total order relation defined this means
that the data is sorted in both sequences.

To tell if the S1 and S2 contain the same set of elements we can use two pointers
to walk through each item in each sequence one step at a time to compare the values
at each index to ensure they are a match. As soon as we detect a mismatch
we know that the sequences do not contain the same set of elements. If we can
iterate to the end of both sequences at the same time then we have a match.

1. Analyze the running time of this method.

The time complexity is dependent on the size of `n` elements and is
therefore a linear time algorithm `O(n)`.

The space complexity is constant, `O(1)`, because only two pointers
are needed to walk through both sequences. The amount of space required
to perform this algorithm does not change as the input size of `n` changes.

## Question 4
### Problem Statement

Given sequence 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, sort the sequence using the
following algorithms, and illustrate the details of the execution of the
algorithms:

a. merge-sort algorithm.

```plaintext
[3,1,4,1,5,9,2,6,5,3,5,]
[3,1,4,1,5,9,]
[3,1,4,]
[3,1,]
[3,]
[3,1,]
[1,3,4,]
[1,3,4,1,5,9,]
[1,3,4,1,5,]
[1,3,4,1,]
[1,3,4,1,5,]
[1,3,4,1,5,9,]
[1,1,3,4,5,9,2,6,5,3,5,]
[1,1,3,4,5,9,2,6,5,]
[1,1,3,4,5,9,2,6,]
[1,1,3,4,5,9,2,]
[1,1,3,4,5,9,2,6,]
[1,1,3,4,5,9,2,6,5,]
[1,1,3,4,5,9,2,5,6,3,5,]
[1,1,3,4,5,9,2,5,6,3,]
[1,1,3,4,5,9,2,5,6,3,5,]
```

b. quick-sort algorithm.
* Choose a partitioning strategy you like to pick a pivot element from the sequence.
* Analyze how different portioning strategies may impact on the performance of the sorting algorithm.

For choosing a pivot I chose to use the value in the last element of the sequence.
Alternative, strategies include choosing a random pivot in each sub-sequence.

Using the last item in the sub-sequence as the pivot:

```plaintext
[3,1,4,1,5,9,2,6,5,3,]
[3,1,4,1,2,]
[1,1,]
[1,]
[]
[1,]
[1,1,]
[1,1,2,3,4,]
[1,1,2,]
[1,1,2,3,3,]
[1,1,2,3,3,4,5,6,5,9,]
[1,1,2,3,3,4,]
[1,1,2,3,3,4,5,5,5,9,]
[1,1,2,3,3,4,5,5,]
[1,1,2,3,3,4,5,5,5,6,]
```

## Question 5
### Problem Statement

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

#### Depth First Traversal

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

#### Breadth First Traversal

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

#### Adjacency List

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

#### Adjacency Matrix

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

#### Traverse Every Edge

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

## Question 6
### Problem Statement

Why does the method `remove(x)` in the `RedBlackTree` implementation
perform the assignment `u:parent = w:parent?`
Shouldn’t this already be done by the call to `splice(w)`?

It is possible that more than one rotation needs to occur so assigning the new parent
is necessary.

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

## Question 7
### Problem Statement

Implement the `remove(u)` method, that removes the node `u` from a
`MeldableHeap`. This method should run in `O(log n)` expected time.

```java
class MeldableHeap {
  Node<T> merge(Node<T> h1, Node<T> h2) {
    if (h1 == nil) return h2;
    if (h2 == nil) return h1;
    if (compare(h2.x, h1.x) < 0) return merge(h2, h1);

    if (rand.nextBoolean()) {
      h1.left = merge(h1.left, h2);
      h1.left.parent = h1;
    } else {
      h1.right = merge(h1.right, h2);
      h1.right.parent = h1;
    }
    return h1;
  }

  boolean add(T x) {
    Node<T> u = newNode();
    u.x = x;
    r = merge(u, r);
    r.parent = nil;
    n++;
    return true;
  }

  T remove() {
    T x = r.x;
    r = merge(r.left, r.right);
    if (r != nil) r.parent = nil;
    n--;
    return x;
  }
}
```
[Source](https://www.aupress.ca/app/uploads/120226_99Z_Morin_2013-Open_Data_Structures.pdf)

An implementation of `meldable_heap_remove(u)` can be found in `./meldable_heap.c`.

## Question 8
### Problem Statement

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

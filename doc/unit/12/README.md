# Graphs

## Directed graph

```plaintext
G = (V,E) where
* V is a set of vertices
* E is a set of ordered pairs of vertices called edges
```

An edge `(i, j)` is directed from `i` to `j`;

* `i` is the source
* `j` is the target

A `path` in `G` is a sequence of vertices.

Typical operations:

* `addEdge(i,j)`: Add the edge (i, j) to E. `O(1)` time.
* `removeEdge(i,j)`: Remove the edge `(i, j)` from E. `O(1)` time.
* `hasEdge(i, j)`: Check if the edge `(i, j)` is an element of E. `O(1)` time.
* `outEdges(i)`: Return a `List` of all ints `j` such that `(i,j)` is an element of E. `O(n)` time.
* `inEdges(i)`: Return a `List` of all ints `j` such that `(j,i)` is an element of E. `O(n)` time.

`O(n^2)` space.

### AdjacencyMatrix: Representing a Graph by a Matrix

Is a way of representing an `n` vertex graph `G = (V,E)`
by an `n x m` matrix, `a`, whose entries are boolean values.

```java
int n;
boolean[][] a;

AdjacencyMatrix(int nO) {
  n = nO;
  a = new boolean[n][n];
}
```

The matrix entry `a[i][j]` is defined as:

```plaintext
a[i][j] = { true if (i, j) element of E otherwise false
```

```java
void addEdge(int i, int j) {
  a[i][j] = true;
}

void removeEdge(int i, int j) {
  a[i][j] = false;
}

boolean hasEdge(int i, int j) {
  return a[i][j];
}

List<Integer> outEdges(int i) {
  List<Integer> edges = new ArrayList<Integer>();
  for (int j = 0; j < n; j++)
    if (a[i][j])
      edges.add(j);
  return edges;
}

List<Integer> inEdges(int i) {
  List<Integer> edges = new ArrayList<Integer>();
  for (int j = 0; j < n; j++)
    if (a[j][i])
      edges.add(j);
  return edges;
}
```

It is large. It stores `n x n` boolean matrix, so it requires
at least `n^2` bits of memory.

### AdjacencyLists: A Graph as a Collection of Lists

representations of graphs take a more vertex-centric approach.
There are many possible implementations of adjacency lists.

Operations:

* `addEdge(i, j)`: `O(1)` time
* `removeEdge(i, j)`: `O(deg(1))` time
* `hasEdge(i, j)`: `O(deg(1))` time
* `outEdges(i)`: in `O(1)` time
* `inEdges(i)`: in `O(n + m)` time

`O(n + m)` space.


```java
int n;
List<Integer>[] adj;

AdjacencyLists(int nO) {
  n = nO;
  adj = (List<Integer>[])new List[n];
  for (int i = 0; i < n; i++)
    adj[i] = new ArrayStack<Integer>();
}

void addEdge(int i, int j) {
  adj[i].add(j);
}

void removeEdge(int i, int j) {
  Iterator<Integer> it = adj[i].iterator();
  while (it.hasNext()) {
    if (it.next() == j) {
      it.remove();
      return;
    }
  }
}

boolean hasEdge(int i, int j) {
  return adj[i].contains(j);
}

List<Integer> outEdges(int i) {
  return adj[i];
}

List<Integer> inEdges(int i) {
  List<Integer> edges = new ArrayStack<Integer>();
  for (int j = 0; j < n; j++)
    if (adj[j].contains(i))
      edges.add(j);
  return edges;
}
```

## Graph Traversal

### Breadth-First Search

starts at a vertex `i` and visits, first the neighbours of `i`,
then the neighbours of the neighbours of `i`, then the
neighbours of the neighbours of the neighbours of `i`, and so on.

It uses a `queue` and makes sure that the same vertex is
not added more than once. It does this be keep track of each 
vertex that has been visited.

```java
void bfs(Graph g, int r) {
  boolean[] seen = new boolean[g.nVertices()];
  Queue<Integer> q = new SLList<Integer>();
  q.add(r);
  seen[r] = true;
  while (!q.isEmpty()) {
    int i = q.remove();
    for (Integer j : g.outEdges(i)) {
      if (!seen[j]) {
        q.add(j);
        seen[j] = true;
      }
    }
  }
}
```

time complexity: when using an adjacency list `O(n+m)`.

BFS is useful for computing shortest paths.

### Depth-First Search

is similar to the standard algorithm for traversing binary trees.
It fully explores one subtree before returning to the current
node and then exploring the other subtree. Another way to
think of depth-first search is by saying that it is similar
to breadth-first search except that it uses a stack instead
of a queue.

Each node has a state:

* not visited
* visited
* visiting

Think of it as a recursive algorithm.

```java
void dfs(Graph g, int r) {
  byte[] c = new byte[g.nVertices()];
  dfs(g, r, c);
}

// uses recursive stack
void dfs(Graph g, int i, byte[] c) {
  c[i] = grey;
  for (Integer j : g.outEdges(i)) {
    if (c[j] == white) {
      c[j] = grey;
      dfs(g, j, c);
    }
  }
  c[i] = black;
}

void dfs2(Graph g, int r) {
  byte[] c = new byte[g.nVertices()];
  Stack<Integer> s = new Stack<Integer>();
  s.push(r);

  while (!s.isEmpty()) {
    int i = s.pop();
    if (c[i] == white) {
      c[i] = grey;
      for (int j : g.outEdges(i))
        s.push(j);
    }
  }
}
```

time complexity: when using an adjacency list `O(n+m)` time.

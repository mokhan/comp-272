Chapter 8: Scapegoat Trees

> when something goes wrong, the first thing people tend to do is find someone to blame (the scapegoat).

A Scapegoat tree implements the Sorted Set, `SSet`, interface.
The tree supports the operations:

| operation | time complexity |
| ------------- | ------------- |
| `add()` | O(log n) |
| `remove()` | O(log n) |
| `find()` | O(log n) |

Balanced by partial rebuilding operations.

* keeps track of the number of nodes `n`.
* keeps a counter, `q`, that maintains an upper-bound on the number of nodes.

At all times, `n` and `q` obey the following inequalities:

> q/2 <= n <= q

credit schema: Each node stores a number of credits.

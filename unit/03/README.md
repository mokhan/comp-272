# Study Activities

Study the following sections from Pat Morin’s textbook:

1. SLList: A Singly-Linked List
2. DLList: A Doubly-Linked List
3. SEList: A Space-Efficient Linked List

Go to Data Structure Visualizations at http://www.cs.usfca.edu/~galles/visualization/Algorithms.html, and try the following:

* Stack: Linked List Implementation
* Queues: Linked List Implementation
* Lists: Array Implementation (available in Java version)
* Lists: Linked List Implementation (available in Java version)

# Linked Lists

Have advantages and disadvantages over array based List interface.

Advantage

* more dynamic

Disadvantage:

* using `get(i)` or `set(i, x)` in constant time.

## Singly-Linked List

SLList: is a sequence of Nodes with a reference to a value and the next node.

```java
class Node {
  T x;
  Node next;
}
```

For efficiency the variables `head` and `tail` are used to keep track of the first and last node.

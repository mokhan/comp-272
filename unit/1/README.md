
## The need for efficiency

* Number of operations
* Processor speeds
* Bigger data sets

## Interfaces

An `interface` sometimes also called an `abstract data type`, defines the
set of operations supported by a data structure and the semantics,
or meaning, of those operations.

### Queue

* `add(x)`: add a value to the queue (a.k.a enqueue, push)
* `remove()`: remove the next value from the queue and return it. (a.k.a. dequeue, shift)

FIFO (first-in-first-out) removes items in the same order they were added.

A priority Queue always removes the smallest element from the Queue, breaking ties arbitrarily.
`remove()` is sometimes called `deleteMin()`.

### Stack

LIFO (last-in-first-out) the most recently added element is the next one removed.

* `add(x)`: add a value to the queue (a.k.a enqueue, push)
* `remove()`: `pop()` the item at the top of the stack.

### Deque

Is a generalization of both the FIFO Queue and the LIFO Queue (stack).
A deque represents a sequence of elements, with a front and a back.

### List

Represents a sequence, x0,...,xn-1, of values.

* `size()`: return the length of the list.
* `get(i)`: return the value xi
* `set(i, x)`: set the value of xi to equal to x
* `add(i, x)`: add x at position i, displacing xi,...,xn-1;
* `remove(i)`: remove the value xi displacing xi+1,...,xn-1;

The operations can be implemented with a Deque interface.

* `addFirst(x)` -> `add(0, x)`
* `removeFirst()` -> `remove(0)`
* `addLast(x)` -> `add(size(), x)`
* `removeLast()` -> `remove(size() - 1)`

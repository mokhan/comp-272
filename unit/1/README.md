
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

### USet

The `USet` interface represents an unordered set of unique elements, which
mimics a mathematical set. A `USet` contains `n` distinct elements; no
element appears more than once; the elements are in no specific order. A
`USet` supports the following operations:

* `size()`: return the number, `n`, of elements in the set.
* `add(x)`: add the element `x` to the set if not already present;
* `remove(x)`: remove `x` from the set;
* `find(x)`: find `x` in the set if it exists

### SSet

The `SSet` interface represents a sorted set of elements. An `SSet` stores elements
from some total order so that any two elements x and y can be compared. In code
examples, this will be done with a method called `compare(x, y)` in which:

* < 0 if x < y
* > 0 if x > y
* = 0 if x == y

An `SSet` supports the `size()` and `add()` and `remove()` methods with
exactly the same semantics as in the `USet` interface. The difference
between a `USet` and an `SSet` is in the `find(x)` method:

> successor search: locate x in the sorted set;
> find the small element y in the set such that y >= x.
> return y or null if no such element exists.


The extra functionality provided by a SSet usually comes with a price that
includes both a larger running time and a higher implementation complexity.
SSet implementations may have a `find(x)` running time of of logarithmic
and a USet may have a running time of constant time.


## Math Review

### Exponentials and Logarithms

The expression b^x denotes the number `b` raised to the power of `x`.

* when x is negative, b^x = 1/(b^-x)
* when x is 0, b^x = 1


```text
b^x = b * b * ... x b
      |____________|
            |
         x times
```

```ruby
b ** x = (x.times.inject(1) { |m, _| m * b }
```

```irb
irb(main):001:0> 2 ** 10
=> 1024
irb(main):002:0> 10.times.inject(1) { |m, _| m * 2 }
=> 1024
```

log b(k) deontes base-b logarithm of k. i.e b^x = k

```text
  log b(k) == b^x = k
```

```ruby
irb(main):016:0> 2 ** 10
=> 1024
irb(main):017:0> Math.log2(1024)
=> 10.0
```

An informal way to think about logarithms is to think of logb(k) as the number
of times we have to divide k by b before the result is less than or equal to 1.

For example, when one does binary search, each comparison reduces the number of
possible answers by a factor of 2. This is repeated until there is at most one
possible answer. Therefore the number of comparisons done by binary search when there
are initially at most n + 1 possible answers is at most log2(n+1).

Another logarithm that comes up several times in this book is the natural logarithm.
Here we use the notation ln k to denote log e(k), where e -- Euler's constant -- is given by:

![eulers constant](./img/eulers-constant.png)

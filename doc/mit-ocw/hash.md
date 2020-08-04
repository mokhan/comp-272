# Hashing

https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/lecture-8-hashing-with-chaining/

movitation

* database
* compilers and interpreters
* network router
* substring search
* string commonalities
* file/dir synchronization

Direct Access table:

  ----------
0 |        |
1 |        |
2 |        |
3 |        |
4 |        |
  | ...    |
  | ...    |
  | ...    |
  ----------

Hash requires mapping to an integer.

ideally:

* prehash hash(x) == hash(y) only when x == y

badness:

1. keys may not be non negative integers
1. gigantic memory hog

hashing -> hatchet

- reduce universe of all possible keys and reduce them down to some reasonable set of integers.
- idea: m = theta(n)
  - size of table proportial to size of # of things.

    -----------
0   | | | | | |
    ----------
1   |         |
    ----------
2   |         |
    ----------
3   |         |
    ----------
4   |         |
    ----------
    | ...     |
    ----------
    | ...     |
    ----------
m-1 | ...     |
    ----------

Collision: Multiple keys map to same slot in hash table.
* h(ki) == h(kj) but ki <> kj
* we can use chaining

How to define?

* function (h)
* all keys map to `h = { 0, ..., m-1 }`

Two ways to deal with collisions:

* Chaining: store collisions as a list. (i.e. linked list)
* Open addressing

## Chaining

    ----------
0   |         | --> (item1) --> (item2) --> (nil)
    ----------
1   |         |
    ----------
2   |         |
    ----------
3   |         |
    ----------
4   |         |
    ----------
    | ...     |
    ----------
    | ...     |
    ----------
m-1 | ...     |
    ----------

Worst case:

* theta(n) (i.e. all items have a collision)

Simple uniform hashing:

* Convenient for analysis.
* each key is equally likely to be hashed to any slot of the table, independent of where other keys hashing.

Analysis:

* expected length of a chain for n keys, m slots.
  * n/m == alpha == load factor
  * O(1 + alpha)

## Hash functions:

1. division method:
  * `h(k) == k mod m`
  * works okay if `m` is prime and not close to power of 2 or power of 10.
2. multiplication method:
  * `h(k) = [(a*k) mod 2^w] >> (w - r)`
3. Universal hasing:
  * `h(k) = [(ak+b) mod p] mod m
    * `a`, `b` are random between 0 and `p-1`. p is a big prime number larger than the universe.
    * {0, ..,p-1}
  * worst case keys: k1 != k2
    * `1/m`

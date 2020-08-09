# Hashing

[video][mit-ocw]

## Motivation

* database
* compilers and interpreters
* network router
* substring search
* string commonalities
* file/dir synchronization

Direct Access table:

  ----------
0 |        |
  ----------
1 |        |
  ----------
2 |        |
  ----------
3 |        |
  ----------
4 |        |
  ----------
  | ...    |
  ----------
  | ...    |
  ----------
  | ...    |
  ----------

> Hash requires mapping to an integer.

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
  * `h(k) = [(ak+b) mod p] mod m`
    * `a`, `b` are random between 0 and `p-1`. p is a big prime number larger than the universe.
    * `{0, ..,p-1}`
  * worst case keys: k1 != k2
    * `1/m`

## How to choose m?

* Want `m = theta(n)`
  * `0(1)`

Idea:

> Start small; grow/shrink as necessary

E.g.

* If n > m: grow table

* grow table:
  * m -> m'
    * make table of size `m'`
    * build new hash function `h'`
    * rehash
      * for item in T:
        * t:insert(item)
    * `m' = 2m` table doubling

Amortization:
* operation takes `T(n) amortized`
  * if `k` operations take <= `k*T(n)` time
* spread out the high cost so you pay a little bit, but more often.
* ~ Think of meaning `T(n)` on average, where average is taken over all the oeprations.

> spread out the high cost so that it's cheap on average all the time.

## Open Adressing

* no chaining
* use arrays
* m: # of slots in the table
* m >= # of elements

```plaintext
----------
| item 1 |
----------
| item 2 |
----------
|        |
----------
|        |
----------
```

probing: try to see if we can insert something into the hashtable.
if we fail, we will compute a slightly different hash until we
find an empty slot that we can insert into this table.

Hash function specifies the order of slots to probe
for a key. (for insert/search/delete)

hash function `h(U, trial_count)`

* U: universe of keys
* trial_count: integer between 0 -> m-1

`h(k,1)`
arbitrary key k

h(k,1), h(k,2), ... h(k, m-1)

to be a permutation of 0,1 ... m-1

```plaintext
  ----------
0 |        |
  ----------
1 |        |
  ----------
2 |        |
  ----------
3 |        |
  ----------
4 |        |
  ----------
5 |        |
  ----------
6 |        |
  ----------
7 |        |
  ----------
```

* `insert(k,v)`: keep probing until an empty slot is found. insert item when found.
* `search(k)`: As long as the slots encountered are occupied by keys != k. keep probing until you either encounter k or find an empty slot.

## Cryptographic Hash


[mit-ocw]: https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/lecture-8-hashing-with-chaining/

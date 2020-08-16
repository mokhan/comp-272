# Learning Profile for Assignment #2 - Computer Science 272: Data Structures and Algorithms

Name: Mo Khan
Student ID: 3431709

## Question 1
### Problem Statement

Design an algorithm for the following operations for a binary tree BT, and show the worst-case running times for each implementation:
* preorderNext(x): return the node visited after node x in a pre-order traversal of BT.
* postorderNext(x): return the node visited after node x in a post-order traversal of BT.
* inorderNext(x): return the node visited after node x in an in-order traversal of BT.

### Description of the Code

I chose to implement the binary tree traversal using
a Visitor design pattern. The `traverse` function
accepts a binary tree node, a callback function and
the type of traversal to perform.

The traversal uses recursion to visit each node in the
binary tree in linear time. The space complexity is determined
by the size of the tree because each recursive call
adds another frame to the call stack.

### Errors and Warnings

I wrote unit tests to to cover several different happy path
scenarios and to cover the base case conditions of the
recursive function.

```bash
モ cd 01/ && make clean && make test && ./build/test
rm -fr build
mkdir build
clang    -c -o build/binary_tree.o binary_tree.c
clang    -c -o build/binary_tree_test.o binary_tree_test.c
clang build/binary_tree.o build/binary_tree_test.o -lcgreen -o build/test
Running "main" (21 tests)...
  "binary_tree_tests": 72 passes in 10ms.
  Completed "main": 72 passes in 10ms.
```

### Sample Input and Output

The file `01/main.c` includes a small program that provides
and example of the tree traversal. It starts by print out
the binary tree to the console then prints the order each
node is visited during each type of traversal.

```bash
モ cd 01/ && make clean && make && ./build/program
rm -fr build
mkdir build
clang    -c -o build/binary_tree.o binary_tree.c
clang    -c -o build/main.o main.c
clang build/binary_tree.o build/main.o -o build/program
=== COMP-272 - Assignment 02 - Question 01 ===
(100)
  (200)
    (400)
    (500)
  (300)

=== Pre order traversal ===
100 200 400 500 300

=== In order traversal ===
400 200 500 100 300

=== Post order traversal ===
400 500 200 300 100
```

### Discussion

This version of the traversal requires the calling code
to capture each node that is visited during the traversal.
This ensures that the traversal operates in O(n) time
but allows the calling code to cache the result of the traversal
in a way that makes sense for it.

## Question 2
### Problem Statement

Design a recursive linear-time algorithm that
tests whether a binary tree satisfies the
search tree order property at every node.

### Description of the Code

To determine if a binary tree satisfies the binary
search tree order property I needed to check each
node in the binary tree to make sure that the item
in the left side of the node is less than the node itself
and that the item in the right side of the node is
greater than itself. Each descendant node must also be
greater or less than each ancestor node depending on which side
of the tree that node is relative to the ancestor.

To perform this check I kept track of the minimum
and maximum values that any node can be while traversing
down the tree.

For example, when traversing down a left sub tree each
node in the left sub tree must be between the minimum
value and the current node. When traversing down the
right subtree each node must be between the value in
the current node and the maximum value.

To kick start the recursive call I specified an arbitrary
min and max values that matched the boundary of the size of
the integer. So a range (2^32/2 * -1) and (2^32/2 - 1) was used.

The base case for the recursive call is when the subtree
that is visited is a NULL.

### Errors and Warnings

I wrote unit tests to test the happy day scenarios, the base
case and a couple of edge cases.

```bash
モ make clean && make test && ./build/test
rm -fr build
mkdir build
clang    -c -o build/btree.o btree.c
clang    -c -o build/btree_test.o btree_test.c
clang build/btree.o build/btree_test.o -lcgreen -o build/test
Running "main" (7 tests)...
  "binary_search_tree_tests": 7 passes in 3ms.
  Completed "main": 7 passes in 4ms.
```

A full list of tests cases can be found in `02/*_test.c`.

### Sample Input and Output

To make it easier to see that the checks are working as
expected, I included a program in `02/main.c` that will
build a binary search tree and a regular binary tree and
check to see if either matches the properties of a binary
search tree.

Sample output can be seen below:

```bash
モ cd 02/ && make clean && make && ./build/program
rm -fr build
mkdir build
clang    -c -o build/btree.o btree.c
clang    -c -o build/main.o main.c
clang build/btree.o build/main.o -o build/program
=== COMP-272 - Assignment 02 - Question 02 ===
Binary Search Tree
---------
10
  -5
    -10
     5
  25
    23
    36
Is a binary search tree? y

Binary Tree
---------
10
   0
    -1
    21
  25
    16
    32
Is a binary search tree? n

Bye
```

### Discussion

The recursive version of the check operates in
`O(n)` time and `O(n)` space. The space is due
to the allocation of a stack frame for each
recursive call in the call stack. An iterative
version of this same algorithm would also
operate in linear time but could benefit
from `O(1)` space by using pointers.

## Question 3
### Problem Statement

Illustrate what happens when the sequence 1, 5, 2, 4, 3 is added to an empty
ScapegoatTree, and show where the credits described in the proof of Lemma 8.3 go,
and how they are used during this sequence of additions.

In an unbalanced binary tree the insertion of `1,5,2,4,3` would
look like the following:

```plaintext
Insert 1:
           (1)

Insert 5:
           (1)
              \
              (5)

Insert 2:
           (1)
          /   \
        (2)   (5)

Insert 4:
           (1)
          /   \
        (2)   (5)
             /
           (4)

Insert 3:

           (1)
          /   \
        (2)   (5)
             /
           (4)
          /
        (3)
```

The above diagram illustrates some negative consequences
for having an unbalanced binary tree. This includes needing
to visit more nodes than necessary to perform a search and
can lead to worst case searches of `O(n)` time.

For example:

```plaintext
  (1)
    \
    (2)
      \
      (3)
        \
        (4)
          \
          (5)
```

The scapegoat tree allows the binary tree to remain
balanced so that searches can operate in `O(logn)` time.
It also does this by maintaining constant space `O(1)`.
Other, balanced binary search tree algorithms like the
AVL tree or Red-Black tree typically require adding additional
data to each node in the tree in order to keep the tree balanced.

The insertion of `1,5,2,4,3` into a scapegoat tree would look 
like the following:

```plaintext
Insert 1:
           (1)     0/1 > 2/3: false

Insert 5:
           (1)     1/2 > 2/3: false
              \
              (5)  0/1 > 2/3: false

Insert 2:
           (1)     1/2 > 2/3: false
          /   \
        (2)   (5)  0/1 > 2/3: false

Insert 4:
           (1)     2/3 > 2/3: false
          /   \
        (2)   (5)  1/2 > 2/3: false
             /
           (4)     0/1 > 2/3: false

Insert 3:

           (1)     3/4 > 2/3: true (scapegoat)
          /   \
        (2)   (5)  2/3 > 2/3: false
             /
           (4)     1/2 > 2/3: false
          /
        (3)        0/1 > 2/3: false
```

The next step is to rebalance from the scapegoat node.

Rebalance:

1. collect nodes in sorted order: [1,3,4,5]
1. find new root: size/2 = 4/2 = 2
1. 3 is the second node and is selected as the new root
1. [1] is moved to the left subtree
1. [4,5] are moved to the right subtree

The final result is a balanced binary search tree.

```plaintext
          (3)
         /   \
       (2)   (4)
      /        \
    (1)        (5)
```

### Description of the Code

The code implements the regular binary tree insertion
but it does not implement the rebalancing.

### Errors and Warnings

The tests can be viewed in `03/*_test.c`.

```bash
モ make clean && make test && ./build/test
rm -fr build
mkdir build
clang    -c -o build/btree.o btree.c
clang    -c -o build/btree_test.o btree_test.c
clang build/btree.o build/btree_test.o -lcgreen -o build/test
Running "main" (6 tests)...
 1
   5
     2
       4
         3
  "binary_search_tree_tests": 20 passes in 3ms.
Completed "main": 20 passes in 3ms.
```

### Sample Input and Output

The example program in `03/main.c` displays
a visual representation of an unbalanced and
a balanced binary search tree.

```bash
モ cd 03/ && make clean && make && ./build/program
rm -fr build
mkdir build
clang    -c -o build/btree.o btree.c
clang    -c -o build/main.o main.c
clang build/btree.o build/main.o -o build/program
=== COMP-272 - Assignment 02 - Question 03 ===
Tree 1: unbalanced tree
 1
   5
     2
       4
         3
Tree 2: balanced tree
 3
   2
     1
   4
     5
Bye
```

### Discussion

Rebalancing a tree can be a tricky operation and
it can slow down insertions into the tree.
During rebalancing it is important to choose
a new root to reduce too much rebalancing operations.

## Question 4
### Problem Statement

Implement a commonly used hash table in a program that handles collision using linear probing.

Using (K mod 13) as the hash function, store the following elements in the table:

{1, 5, 21, 26, 39, 14, 15, 16, 17, 18, 19, 20, 111, 145, 146}.

### Description of the Code

To implement a hash table I chose to store
a linked list in each bucket and perform a
linear, `O(n)`, scan to find the correct node.

This could have been optimized further by using
a balanced binary search tree and performing
a binary search to find the correct node
when a collision occurs.

Each node in the linked list is stored as a
2-Tuple (two-ple) to store the key and associated
value.

### Errors and Warnings

Unit tests for the Tuple, List and Btree can
be found in the corresponding files with a `04/*_test.c`
suffix.

```bash
モ cd 04 && make clean && make test && ./build/test
rm -fr build
mkdir build
clang -std=c99   -c -o build/hash.o hash.c
clang -std=c99   -c -o build/list.o list.c
clang -std=c99   -c -o build/tuple.o tuple.c
clang -std=c99   -c -o build/hash_test.o hash_test.c
clang -std=c99   -c -o build/list_test.o list_test.c
clang -std=c99   -c -o build/tuple_test.o tuple_test.c
clang build/hash.o build/list.o build/tuple.o build/hash_test.o build/list_test.o build/tuple_test.o -lcgreen -o build/test
Running "main" (13 tests)...
  "hash_table_tests": 20 passes in 2ms.
  "list_tests": 15 passes in 3ms.
  "tuple_tests": 2 passes in 1ms.
Completed "main": 37 passes in 6ms.
```

### Sample Input and Output

An example program is included in `04/main.c`
that prints a visual representation of the
content of the hash table.

```bash
モ cd 04 && make clean && make && ./build/program
rm -fr build
mkdir build
clang -std=c99   -c -o build/hash.o hash.c
clang -std=c99   -c -o build/list.o list.c
clang -std=c99   -c -o build/tuple.o tuple.c
clang -std=c99   -c -o build/main.o main.c
clang build/hash.o build/list.o build/tuple.o build/main.o -o build/program
=== COMP-272 - Assignment 02 - Question 04 ===
Insert items into hash
(1:10) (5:50) (21:210) (26:260) (39:390) (14:140) (15:150) (16:160) (17:170) (18:180) (19:190) (20:200) (111:1110) (145:1450) (146:1460)
Inspect hash table
 0: [(26:260)(39:390)]
 1: [(1:10)(14:140)]
 2: [(15:150)(145:1450)]
 3: [(16:160)(146:1460)]
 4: [(17:170)]
 5: [(5:50)(18:180)]
 6: [(19:190)]
 7: [(20:200)(111:1110)]
 8: [(21:210)]
 9: [(nil)]
10: [(nil)]
11: [(nil)]
12: [(nil)]
Retrieve each item from the table
(1:10) (5:50) (21:210) (26:260) (39:390) (14:140) (15:150) (16:160) (17:170) (18:180) (19:190) (20:200) (111:1110) (145:1450) (146:1460)
Bye
```

### Discussion

Choosing to back the hash table with a linked
list made it easier to implement the code but
it does come with the cost of time complexity.

By using a balanced binary search tree the
time to look up a key would have been
`O(1)` (compute hash) + `O(logn)` i.e. `O(logn)`.
Using, a linked list changes the time
complexity to `O(1)` + `O(n)` i.e. `O(n)`.

## Question 5
### Problem Statement

Create a subclass of `BinaryTree` whose nodes have fields for storing preorder,
post-order, and in-order numbers.
Write methods `preOrderNumber()`, `inOrderNumber()`, and `postOrderNumbers()`
that assign these numbers correctly.
These methods should each run in `O(n)` time.

### Description of the Code

I chose to write this assignment in `C`, so the notion
of subclassing and inheritance does not apply.

To accommodate the problem statement, I updated the
binary tree struct to include an integer array
that can store up to 32 entries. Each array
includes a cached copy of the traversal order
for pre order, in order and post order traversals.

To fill the cache, the function `btree_(pre|in|post)_order_number`
must be called. The cached traversal is stored
in the root of the tree that is provided.

I chose to use a Stack to perform the traversal in
an iterative way. In previous implementations of the
traversal algorithm for the other questsions in this
assignment I chose to use recursion. This implementation
explicitly uses a stack instead of implicitly through
stack frames in the call stack.

### Errors and Warnings

Unit tests for this can be found in `05/*_test.c`.

```bash
モ make clean && make test && ./build/test
rm -fr build
mkdir build
clang -std=c99   -c -o build/btree.o btree.c
clang -std=c99   -c -o build/stack.o stack.c
clang -std=c99   -c -o build/btree_test.o btree_test.c
clang -std=c99   -c -o build/stack_test.o stack_test.c
clang build/btree.o build/stack.o build/btree_test.o build/stack_test.o -lcgreen -o build/test
Running "main" (14 tests)...
  "btree_tests": 42 passes in 5ms.
  "stack_tests": 10 passes in 2ms.
Completed "main": 52 passes in 7ms.
```

### Sample Input and Output

A sample program can be found in `05/main.c` that
prints out the traversal for an example tree.

```bash
モ cd 05 && make clean && make && ./build/program
rm -fr build
mkdir build
clang -std=c99   -c -o build/btree.o btree.c
clang -std=c99   -c -o build/stack.o stack.c
clang -std=c99   -c -o build/main.o main.c
clang build/btree.o build/stack.o build/main.o -o build/program
=== COMP-272 - Assignment 02 - Question 05 ===
10
   5
     3
     7
  15
    12
    18
Pre order traversal:
10 5 3 7 15 12 18 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

In order traversal:
3 5 7 10 12 15 18 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

Post order traversal:
3 7 5 12 18 15 10 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

Bye
```

### Discussion

Allocating space for 32 values for the pre order, in order and post order
representation for each node in a binary tree is quite wasteful.

An alternative implementation might have returned a linked list
instead of storing this data in an array on each node.

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
### Errors and Warnings
### Sample Input and Output
### Discussion

## Question 3
### Problem Statement

Illustrate what happens when the sequence 1, 5, 2, 4, 3 is added to an empty
ScapegoatTree, and show where the credits described in the proof of Lemma 8.3 go,
and how they are used during this sequence of additions.

### Description of the Code
### Errors and Warnings
### Sample Input and Output
### Discussion

## Question 4
### Problem Statement

Implement a commonly used hash table in a program that handles collision using linear probing.

Using (K mod 13) as the hash function, store the following elements in the table:

{1, 5, 21, 26, 39, 14, 15, 16, 17, 18, 19, 20, 111, 145, 146}.

### Description of the Code
### Errors and Warnings
### Sample Input and Output
### Discussion

## Question 5
### Problem Statement

Create a subclass of `BinaryTree` whose nodes have fields for storing preorder, post-order, and in-order numbers.
Write methods `preOrderNumber()`, `inOrderNumber()`, and `postOrderNumbers()` that assign these numbers correctly.
These methods should each run in `O(n)` time.

### Description of the Code
### Errors and Warnings
### Sample Input and Output
### Discussion

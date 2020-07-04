# Learning Profile for Assignment #1 - Question #2a - Computer Science 272: Data Structures and Algorithms

Name: Mo Khan
Student ID: 3431709

## Problem Statement

Swap two adjacent elements in a list by adjusting only the links (and not the data) using singly-linked list.

## Description of the Code

The singly linked list is represented by a `Node` struct.

The `singly_linked_list.c` file contains the functions related to working
with a `Node` struct. The `Node` struct represents a single node in a
linked list.

## Errors and Warnings

```bash
モ make run_test
mkdir build
clang    -c -o build/singly_linked_list.o singly_linked_list.c
clang    -c -o build/singly_linked_list_test.o singly_linked_list_test.c
clang build/singly_linked_list.o build/singly_linked_list_test.o -lcgreen -o build/test
Running "main" (13 tests)...
  "swap_singly_linked_list_tests": 38 passes in 4ms.
  Completed "main": 38 passes in 4ms.
```

## Sample Input and Output

The program defined in [`main`](./main.c) adds 10 randomly generated
integers to a singly linked list then swaps each pair of items.

```bash
モ make run
mkdir build
clang    -c -o build/singly_linked_list.o singly_linked_list.c
clang    -c -o build/main.o main.c
clang build/singly_linked_list.o build/main.o -o build/program
./build/program
=== COMP-272 - Assignment 1 - Question 2a ===

        [ 83  86  77  15  93  35  86  92  49  21 ]
swap: 0,1
        [ 86  83  77  15  93  35  86  92  49  21 ]
swap: 2,3
        [ 86  83  15  77  93  35  86  92  49  21 ]
swap: 4,5
        [ 86  83  15  77  35  93  86  92  49  21 ]
swap: 6,7
        [ 86  83  15  77  35  93  92  86  49  21 ]
swap: 8,9
        [ 86  83  15  77  35  93  92  86  21  49 ]
```

## Discussion

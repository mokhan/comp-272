# Learning Profile for Assignment #1 - Question #1b - Computer Science 272: Data Structures and Algorithms

Name: Mo Khan
Student ID: 3431709

## Problem Statement:

Implement the stack methods `push(x)` and `pop()` using two queues.

Analyze the running time of the `push(x)` and `pop()` operations based on this implementation.

## Description of the Code

The `push()` function is used to push a new item to the top of the stack.
The `pop()` function is used to pop the item off the top of the stack.

The implementation of the `push()` function operates in linear time `O(n)`.
The implementation of the `pop()` function operates in linear time `O(n)`.

## Errors and Warnings

The design this program I used [cgreen](https://cgreen-devs.github.io/) to unit test the pseudo public
functions of the Stack interface.

The [`stack_test.c`](./stack_test.c) file includes unit tests to cover the following scenarios:

* popping an item off of an empty stack
* popping an item off of the stack
* popping successive items off of the stack
* pushing an item onto a full stack
* pushing an item onto the stack

```bash
モ make run_test
mkdir build
clang    -c -o build/stack.o stack.c
clang    -c -o build/stack_test.o stack_test.c
clang build/stack.o build/stack_test.o -lcgreen -o build/test
Running "main" (3 tests)...
  "stack_tests": 5 passes in 1ms.
Completed "main": 5 passes in 1ms.
```

## Sample Input and Output

```bash
モ make run
clang build/stack.o build/main.o -o build/program
./build/program
=== COMP-272 - Assignment 1 - Question 1b ===
Push: 383
Push: 886
Push: 777
Push: 915
Push: 793
Push: 335
Push: 386
Push: 492
Push: 649
Push: 421

[383,886,777,915,793,335,386,492,649,421]
Pop: 421
[383,886,777,915,793,335,386,492,649]
Pop: 649
[383,886,777,915,793,335,386,492]
Pop: 492
[383,886,777,915,793,335,386]
Pop: 386
[383,886,777,915,793,335]
Pop: 335
[383,886,777,915,793]
Pop: 793
[383,886,777,915]
Pop: 915
[383,886,777]
Pop: 777
[383,886]
Pop: 886
[383]
Pop: 383
[]
Bye
```

## Discussion

# Learning Profile for Assignment #1 - Question #2b - Computer Science 272: Data Structures and Algorithms

Name: Mo Khan
Student ID: 3431709

## Problem Statement

Swap two adjacent elements in a list by adjusting only the links (and not the data) using doubly-linked list.

## Description of the Code
## Errors and Warnings

```bash
モ make run_test
mkdir build
clang    -c -o build/doubly_linked_list.o doubly_linked_list.c
clang    -c -o build/doubly_linked_list_test.o doubly_linked_list_test.c
clang build/doubly_linked_list.o build/doubly_linked_list_test.o -lcgreen -o build/test
Running "main" (22 tests)...
  "swap_doubly_linked_list_tests": 164 passes in 7ms.
  Completed "main": 164 passes in 7ms.
```

## Sample Input and Output

The program defined in [`main.c`](./main.c) adds 10 randomly generated numbers to a
doubly linked list then swaps it pair of nodes from index 0 to the end of the list.

```bash
モ make run
clang    -c -o build/main.o main.c
clang build/doubly_linked_list.o build/main.o -o build/program
./build/program
=== COMP-272 - Assignment 1 - Question 2b ===
        [ (nil<83>86) (83<86>77) (86<77>15) (77<15>93) (15<93>35) (93<35>86) (35<86>92) (86<92>49) (92<49>21) (49<21>nil) ]
swap: 0,1
        [ (nil<86>83) (86<83>77) (83<77>15) (77<15>93) (15<93>35) (93<35>86) (35<86>92) (86<92>49) (92<49>21) (49<21>nil) ]
swap: 2,3
        [ (nil<86>83) (86<83>15) (83<15>77) (15<77>93) (77<93>35) (93<35>86) (35<86>92) (86<92>49) (92<49>21) (49<21>nil) ]
swap: 4,5
        [ (nil<86>83) (86<83>15) (83<15>77) (15<77>35) (77<35>93) (35<93>86) (93<86>92) (86<92>49) (92<49>21) (49<21>nil) ]
swap: 6,7
        [ (nil<86>83) (86<83>15) (83<15>77) (15<77>35) (77<35>93) (35<93>92) (93<92>86) (92<86>49) (86<49>21) (49<21>nil) ]
swap: 8,9
        [ (nil<86>83) (86<83>15) (83<15>77) (15<77>35) (77<35>93) (35<93>92) (93<92>86) (92<86>21) (86<21>49) (21<49>nil) ]
```

## Discussion

# Learning Profile for Assignment #1 - Question #05 - Computer Science 272: Data Structures and Algorithms

Name: Mo Khan
Student ID: 3431709

## Problem Statement

Write a method, `reverse()`, that reverses the order of elements in a DLList.

## Description of the Code

To reverse the linked list I chose to iterate from the head of the
linked list to the tail and swap the next and previous pointers while
iterating.

After iterating through the list, the previous tail becomes the new head of the list.

## Errors and Warnings

```bash
モ make run_test
clang build/doubly_linked_list.o build/doubly_linked_list_test.o -lcgreen -o build/test
cgreen-runner -c -v build/test
Discovered DoublyLinkedList:when_reversing_a_short_list (CgreenSpec__DoublyLinkedList__when_reversing_a_short_list__)
Discovered DoublyLinkedList:when_reversing_an_empty_list (CgreenSpec__DoublyLinkedList__when_reversing_an_empty_list__)
Discovered 2 test(s)
Opening [build/test] to run all 2 discovered tests ...
Running "test" (2 tests)...
  "DoublyLinkedList": 8 passes in 2ms.
  Completed "test": 8 passes in 2ms.
```

## Sample Input and Output

```bash
モ make run
clang    -c -o build/main.o main.c
clang build/doubly_linked_list.o build/main.o -o build/program
./build/program
=== COMP-272 - Assignment 1 - Question 5 ===
Before:
        [ (nil<0>0) (0<0>1) (0<1>2) (1<2>3) (2<3>4) (3<4>5) (4<5>6) (5<6>7) (6<7>8) (7<8>9) (8<9>nil) ]
        Reversing...
After:
        [ (nil<9>8) (9<8>7) (8<7>6) (7<6>5) (6<5>4) (5<4>3) (4<3>2) (3<2>1) (2<1>0) (1<0>0) (0<0>nil) ]
```

## Discussion

# Learning Profile for Assignment #1 - Question #1a - Computer Science 272: Data Structures and Algorithms

Name: Mo Khan
Student ID: 3431709

## Problem Statement

* Describe the meaning of the essential methods `add(x)`, `deleteMin()`, and `size()` that are supported by the priority queue interface.
* Implement those methods using a singly-linked list.
* Analyze the running time of the `add(x)` and `deletMin()` operations based on this implementation.

## Description of the Code

The `add()` function is used to add a new item to the priority queue.
The `deleteMin()` function is used to remove and return the item in the queue with the lowest priority.
The `size()` function is used to determine the total number of items that are currently in the queue.

This implementation of the `add()` function operates linear time `O(n)`.
This implementation of the  `deleteMin(x)` function operates in constant time `O(1)`.

When an item is added to the queue with a priority that duplicates the priority of another item
in the queue, then the new item is removed in the same order that it was added in. .i.e. it is removed
after each other item that had a duplicate priority that was added before it.

## Errors and Warnings

I chose to use [cgreen](https://github.com/cgreen-devs/cgreen) to write unit tests for designing the different
function to support the Queue interface.

Below is an example run of the test suite:

```bash
モ make run_test
clang build/priority_queue.o build/priority_queue_test.o -lcgreen -o build/test
cgreen-runner -c -v build/test
Discovered PriorityQueue:adds_a_node (CgreenSpec__PriorityQueue__adds_a_node__)
Discovered PriorityQueue:removes_the_node_with_the_lowest_priority (CgreenSpec__PriorityQueue__removes_the_node_with_the_lowest_priority__)
Discovered PriorityQueue:returns_size (CgreenSpec__PriorityQueue__returns_size__)
Discovered PriorityQueue:when_adding_data_out_of_order (CgreenSpec__PriorityQueue__when_adding_data_out_of_order__)
Discovered PriorityQueue:when_adding_random_values_with_random_priority_it_returns_the_minimum_priority_value_correctly (CgreenSpec__PriorityQueue__when_adding_random_values_with_random_priority_it_returns_the_minimum_priority_value_correctly__)
Discovered PriorityQueue:when_removing_it_decreases_the_size (CgreenSpec__PriorityQueue__when_removing_it_decreases_the_size__)
Discovered PriorityQueue:when_removing_node_from_empty_queue (CgreenSpec__PriorityQueue__when_removing_node_from_empty_queue__)
Discovered PriorityQueue:when_removing_the_last_node_it_decrements_the_count_correctly (CgreenSpec__PriorityQueue__when_removing_the_last_node_it_decrements_the_count_correctly__)
Discovered 8 test(s)
Opening [build/test] to run all 8 discovered tests ...
Running "test" (8 tests)...
  "PriorityQueue": 17 passes in 5ms.
Completed "test": 17 passes in 5ms.
```

The test cases include:

* add a node to an empty queue
* remove a node from the head of the queue
* removing a node from an empty queue
* removing the last node
* adding nodes out of order

Please see [`priority_queue_test.c`](./priority_queue_test.c) for more details.

## Sample Input and Output

I included a program that generates 10 random numbers with 10 random priorities and
enqueues them onto the queue.

The program then prints a visual tree of the queue and loops until each item is removed from the queue.
The `deleteMin` function removes the item with the lowest priority until the queue is empty.

```bash
モ make run
clang build/priority_queue.o build/main.o -o build/program
./build/program
=== COMP-272 - Assignment 1 - Question 1a ===
Enqueue: 7      249
Enqueue: 3      658
Enqueue: 0      272
Enqueue: 4      878
Enqueue: 3      709
Enqueue: 0      165
Enqueue: 2      42
Enqueue: 7      503
Enqueue: 7      729
Enqueue: 0      612

Dequeue: 272
Items (9): [ (0,165) (0,612) (2,42) (3,658) (3,709) (4,878) (7,249) (7,503) (7,729) ]
Dequeue: 165
Items (8): [ (0,612) (2,42) (3,658) (3,709) (4,878) (7,249) (7,503) (7,729) ]
Dequeue: 612
Items (7): [ (2,42) (3,658) (3,709) (4,878) (7,249) (7,503) (7,729) ]
Dequeue: 42
Items (6): [ (3,658) (3,709) (4,878) (7,249) (7,503) (7,729) ]
Dequeue: 658
Items (5): [ (3,709) (4,878) (7,249) (7,503) (7,729) ]
Dequeue: 709
Items (4): [ (4,878) (7,249) (7,503) (7,729) ]
Dequeue: 878
Items (3): [ (7,249) (7,503) (7,729) ]
Dequeue: 249
Items (2): [ (7,503) (7,729) ]
Dequeue: 503
Items (1): [ (7,729) ]
Dequeue: 729
Items (0): [ ]
Bye
```

## Discussion

I chose to make this queue store signed `int` data and signed `int` priority.
This means that the maximum value that can be used for either the data or priority component
must fit within the range of an `int`.

On this computer the `sizeof(int)` is 4 bytes. This gives a range of `4294967296`
possible values. Because this is a signed integer the range of those values are
`-2,147,483,648` to `2,147,483,647`.

```bash
irb(main):001:0> 2 ** 32
=> 4294967296
irb(main):002:0> (2 ** 32) / 2
=> 2147483648
```

I considered using a `void*` to allow for different data types but I felt that
this would have complicated the solution without enough value to justify the need
for this assignment.

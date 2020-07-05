# Learning Profile for Assignment #1 - Question #6 - Computer Science 272: Data Structures and Algorithms

Name: Mo Khan
Student ID: 3431709

## Problem Statement

Design and implement a MinStack data structure that can store comparable elements and supports the stack operations `push(x)`, `pop()`, and `size()`,
as well as the `min()` operation, which returns the minimum value currently stored in the data structure.

All operations should run in constant time.

## Description of the Code

To keep track of the min value, I chose to use two Stacks.
One stack keeps track of each item that is pushed on.
The second stack keeps track of each new minimum value that is pushed on to the stack.

`push()`, `pop()` and `size()` are operate in constant time.
However, `min` operates in constant time until each of the min values
have been popped off of the min stack. After that it falls back to a linear
time algorithm to determine the next min.

## Errors and Warnings

```bash
モ make run_test
clang build/min_stack.o build/min_stack_test.o -lcgreen -o build/test
cgreen-runner -c -v build/test
Discovered MinStack:when_a_single_item_is_on_the_stack_it_has_a_size_of_one (CgreenSpec__MinStack__when_a_single_item_is_on_the_stack_it_has_a_size_of_one__)
Discovered MinStack:when_a_single_item_is_on_the_stack_it_is_the_min (CgreenSpec__MinStack__when_a_single_item_is_on_the_stack_it_is_the_min__)
Discovered MinStack:when_a_single_item_is_on_the_stack_when_it_is_popped_off_it_returns_a_min_of_null (CgreenSpec__MinStack__when_a_single_item_is_on_the_stack_when_it_is_popped_off_it_returns_a_min_of_null__)
Discovered MinStack:when_a_single_item_is_on_the_stack_when_it_is_popped_off_it_returns_a_size_of_zero (CgreenSpec__MinStack__when_a_single_item_is_on_the_stack_when_it_is_popped_off_it_returns_a_size_of_zero__)
Discovered MinStack:when_a_single_item_is_on_the_stack_when_it_is_popped_off_it_returns_the_item (CgreenSpec__MinStack__when_a_single_item_is_on_the_stack_when_it_is_popped_off_it_returns_the_item__)
Discovered MinStack:when_empty (CgreenSpec__MinStack__when_empty__)
Discovered MinStack:when_empty_it_has_a_min_of_null (CgreenSpec__MinStack__when_empty_it_has_a_min_of_null__)
Discovered MinStack:when_empty_it_has_a_size_of_zero (CgreenSpec__MinStack__when_empty_it_has_a_size_of_zero__)
Discovered MinStack:when_pushing_a_single_integer (CgreenSpec__MinStack__when_pushing_a_single_integer__)
Discovered MinStack:when_pushing_duplicate_values_on_to_the_stack (CgreenSpec__MinStack__when_pushing_duplicate_values_on_to_the_stack__)
Discovered MinStack:when_pushing_multiple_integers_out_of_order (CgreenSpec__MinStack__when_pushing_multiple_integers_out_of_order__)
Discovered 11 test(s)
Opening [build/test] to run all 11 discovered tests ...
Running "test" (11 tests)...
  "MinStack": 39 passes in 7ms.
Completed "test": 39 passes in 7ms.
```

## Sample Input and Output

```bash
モ make run
clang    -c -o build/main.o main.c
clang build/min_stack.o build/main.o -o build/program
./build/program
=== COMP-272 - Assignment 1 - Question 6 ===
Pushing:
==========
Push: 7, Min: 7
	[7]
Push: 24, Min: 7
	[24][7]
Push: 23, Min: 7
	[23][24][7]
Push: 8, Min: 7
	[8][23][24][7]
Push: 5, Min: 5
	[5][8][23][24][7]
Push: 22, Min: 5
	[22][5][8][23][24][7]
Push: 19, Min: 5
	[19][22][5][8][23][24][7]
Push: 3, Min: 3
	[3][19][22][5][8][23][24][7]
Push: 23, Min: 3
	[23][3][19][22][5][8][23][24][7]
Push: 9, Min: 3
	[9][23][3][19][22][5][8][23][24][7]
Push: 15, Min: 3
	[15][9][23][3][19][22][5][8][23][24][7]
Push: 15, Min: 3
	[15][15][9][23][3][19][22][5][8][23][24][7]
Push: 17, Min: 3
	[17][15][15][9][23][3][19][22][5][8][23][24][7]
Push: 17, Min: 3
	[17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Push: 12, Min: 3
	[12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Push: 3, Min: 3
	[3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Push: 2, Min: 2
	[2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Push: 4, Min: 2
	[4][2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Push: 15, Min: 2
	[15][4][2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Push: 12, Min: 2
	[12][15][4][2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Push: 3, Min: 2
	[3][12][15][4][2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Push: 19, Min: 2
	[19][3][12][15][4][2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Push: 9, Min: 2
	[9][19][3][12][15][4][2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Push: 7, Min: 2
	[7][9][19][3][12][15][4][2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Push: 10, Min: 2
	[10][7][9][19][3][12][15][4][2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Popping:
==========
	[10][7][9][19][3][12][15][4][2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Pop: 10, Min: 2
	[7][9][19][3][12][15][4][2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Pop: 7, Min: 2
	[9][19][3][12][15][4][2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Pop: 9, Min: 2
	[19][3][12][15][4][2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Pop: 19, Min: 2
	[3][12][15][4][2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Pop: 3, Min: 2
	[12][15][4][2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Pop: 12, Min: 2
	[15][4][2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Pop: 15, Min: 2
	[4][2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Pop: 4, Min: 2
	[2][3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Pop: 2, Min: 3
	[3][12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Pop: 3, Min: 5
	[12][17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Pop: 12, Min: 5
	[17][17][15][15][9][23][3][19][22][5][8][23][24][7]
Pop: 17, Min: 5
	[17][15][15][9][23][3][19][22][5][8][23][24][7]
Pop: 17, Min: 5
	[15][15][9][23][3][19][22][5][8][23][24][7]
Pop: 15, Min: 5
	[15][9][23][3][19][22][5][8][23][24][7]
Pop: 15, Min: 5
	[9][23][3][19][22][5][8][23][24][7]
Pop: 9, Min: 5
	[23][3][19][22][5][8][23][24][7]
Pop: 23, Min: 5
	[3][19][22][5][8][23][24][7]
Pop: 3, Min: 5
	[19][22][5][8][23][24][7]
Pop: 19, Min: 5
	[22][5][8][23][24][7]
Pop: 22, Min: 5
	[5][8][23][24][7]
Pop: 5, Min: 7
	[8][23][24][7]
Pop: 8, Min: 7
	[23][24][7]
Pop: 23, Min: 7
	[24][7]
Pop: 24, Min: 7
	[7]
Pop: 7, Min: 0

Bye
```

## Discussion

I struggled to find a good algorithm that would guarantee a constant time
implementation of `min()`.

The worst case scenario for this implementation is when the min value is pushed on to
the stack right in the center. Half of the pops will would yield a constant time
implementation of `min()` and the other half would yield a linear time implementation
of `min()`.

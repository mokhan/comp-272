# Computer Science 272 (COMP-272): Data Structures and Algorithms

COMP 272 covers analysis and design of fundamental data structures and engages
learners to use data structures as tools to algorithmically design efficient
computer programs that will cope with the complexity of actual applications.

The course focuses on basic and essential topics in data structures,
including array-based lists, linked lists, skiplists, hash tables,
recursion, binary trees, scapegoat trees, red–black trees, heaps,
sorting algorithms, graphs, and binary trie.

* [Assignments](./doc/assignments)
* [Units](./doc/unit)

Install [cgreen](https://github.com/cgreen-devs/cgreen).

To run example programs:

```bash
$ make run
モ make run
for i in src/01/05 src/01/01b src/01/02b src/01/06 src/01/01a src/01/02a; do cd $i && make clean run && cd -; done
rm -fr build
mkdir build
clang    -c -o build/doubly_linked_list.o doubly_linked_list.c
clang    -c -o build/main.o main.c
clang build/doubly_linked_list.o build/main.o -o build/program
./build/program
=== COMP-272 - Assignment 1 - Question 5 ===
Before:
        [ (nil<0>0) (0<0>1) (0<1>2) (1<2>3) (2<3>4) (3<4>5) (4<5>6) (5<6>7) (6<7>8) (7<8>9) (8<9>nil) ]
Reversing...
After:
        [ (nil<9>8) (9<8>7) (8<7>6) (7<6>5) (6<5>4) (5<4>3) (4<3>2) (3<2>1) (2<1>0) (1<0>0) (0<0>nil) ]

rm -fr build
mkdir build
clang    -c -o build/stack.o stack.c
clang    -c -o build/main.o main.c
clang build/stack.o build/main.o -o build/program
./build/program
=== COMP-272 - Assignment 1 - Question 1b ===
Push: 807
Push: 249
Push: 73
Push: 658
Push: 930
Push: 272
Push: 544
Push: 878
Push: 923
Push: 709

Stack:          [807,249,73,658,930,272,544,878,923,709]
  Pop: 709      [807,249,73,658,930,272,544,878,923]
  Pop: 923      [807,249,73,658,930,272,544,878]
  Pop: 878      [807,249,73,658,930,272,544]
  Pop: 544      [807,249,73,658,930,272]
  Pop: 272      [807,249,73,658,930]
  Pop: 930      [807,249,73,658]
  Pop: 658      [807,249,73]
  Pop: 73       [807,249]
  Pop: 249      [807]
  Pop: 807      []

Bye

rm -fr build
mkdir build
clang    -c -o build/doubly_linked_list.o doubly_linked_list.c
clang    -c -o build/main.o main.c
clang build/doubly_linked_list.o build/main.o -o build/program
./build/program
=== COMP-272 - Assignment 1 - Question 2b ===
        [ (nil<7>49) (7<49>73) (49<73>58) (73<58>30) (58<30>72) (30<72>44) (72<44>78) (44<78>23) (78<23>9) (23<9>nil) ]
swap: 0,1
        [ (nil<49>7) (49<7>73) (7<73>58) (73<58>30) (58<30>72) (30<72>44) (72<44>78) (44<78>23) (78<23>9) (23<9>nil) ]
swap: 2,3
        [ (nil<49>7) (49<7>58) (7<58>73) (58<73>30) (73<30>72) (30<72>44) (72<44>78) (44<78>23) (78<23>9) (23<9>nil) ]
swap: 4,5
        [ (nil<49>7) (49<7>58) (7<58>73) (58<73>72) (73<72>30) (72<30>44) (30<44>78) (44<78>23) (78<23>9) (23<9>nil) ]
swap: 6,7
        [ (nil<49>7) (49<7>58) (7<58>73) (58<73>72) (73<72>30) (72<30>78) (30<78>44) (78<44>23) (44<23>9) (23<9>nil) ]
swap: 8,9
        [ (nil<49>7) (49<7>58) (7<58>73) (58<73>72) (73<72>30) (72<30>78) (30<78>44) (78<44>9) (44<9>23) (9<23>nil) ]

rm -fr build
mkdir build
clang    -c -o build/min_stack.o min_stack.c
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

rm -fr build
mkdir build
clang    -c -o build/priority_queue.o priority_queue.c
clang    -c -o build/main.o main.c
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

rm -fr build
mkdir build
clang    -c -o build/singly_linked_list.o singly_linked_list.c
clang    -c -o build/main.o main.c
clang build/singly_linked_list.o build/main.o -o build/program
./build/program
=== COMP-272 - Assignment 1 - Question 2a ===

        [ 7  49  73  58  30  72  44  78  23  9 ]
swap: 0,1
        [ 49  7  73  58  30  72  44  78  23  9 ]
swap: 2,3
        [ 49  7  58  73  30  72  44  78  23  9 ]
swap: 4,5
        [ 49  7  58  73  72  30  44  78  23  9 ]
swap: 6,7
        [ 49  7  58  73  72  30  78  44  23  9 ]
swap: 8,9
        [ 49  7  58  73  72  30  78  44  9  23 ]
```

To run tests:

```bash
$ make test
```

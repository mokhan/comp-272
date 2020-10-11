# Sample Final Examination

1. Which of the following traversals yields `BADEC`?

```plaintext
  (A)
  / \
(B) (C)
    / \
  (D) (E)
```

a. only in-order
b. only level order
c. only post-order
d. only pre-order
e. pre-order and level order
f. in-order and level order
g. none of the above

2. Which of the following is a post-order traversal of the BST?

a. `ACEDB`
b. `ABDCE`
c. `BDECA`
d. `EDCBA`
e. `BADCE`
f. `BADEC`
g. one of the above. # that's right this says `one` and not `none`. :facepalm:

3. Given `current` (a reference to a list node), which statement may insert an item `x` correctly after the node referenced by current?

a. `current = new ListNode(x, current);`
b. `current.next = new ListNode(x, current.next);`
c. `current.next() = new ListNode(x, current);`
d. `current.next() = new ListNode(x, current.next);`
e. `current = new ListNode(x, current.next);`
f. `current.next = new ListNode(x, current);`
g. none of the above

4. Two sorting algorithms whose worst-case running times are in `O(nlogn)` are:

a. merge-sort, Shellsort
b. heap-sort, quicksort
c. heap-sort, Shellsort
d. insertion sort, merge-sort
e. heap-sort, merge-sort
f. merge-sort, quicksort
g. none of the above

5. The subarray of length 7 shown below is about to be partitioned by quicksort.

```plaintext
[6, 8, 4, 5, 3, 1, 7]
```

The pivot is selected by the "safe choice"; that is, it will be the middle element, 5.
The pivot is then swapped with the last element, 7, and partitioning starts.
At the end of partitioning, the pivot is swapped into place.
At this poit the state of the subarray is:

a. 1,3,4,5,6,8,7
b. 1,3,4,5,8,6,7
c. 1,4,3,5,6,8,7
d. 1,4,3,5,8,6,7
e. 1,3,4,5,6,7,8
f. 1,3,4,5,7,6,8
g. none of the above

6. Recursion is sometimes preferred to iteration because it

a. is generally faster than iteration.
b. requires less memory space.
c. is based on proof by contradiction.
d. may increase the complexity of the solution.
e. is rooted in transfinite induction.
f. is based on the pigeonhole principle.
g. none of the above.

7. Linked lists are ofent implemented with a dummy header node to

a. reduce the execution time of the list operations.
b. fulfill the specifications of the list ADT.
c. identify the beginning of the list.
d. be able to access the first element in Q(1) time.
e. reduce code complexity
f. save memory space.
g. none of the above.

8. When an unordered list of `n` keys is searched sequentially for given key values,
 the average number of key comparisons made by an unsuccessful search is:

a. n
b. log(n)
c. n/2
d. nlog(n)
e. n + n^2
f. n^2log(n)
g. 2n

9. Which data structure would you use in writing a program to check for balance parentheses?

a. binary search tree
b. hash table
c. priority queue
d. queue
e. stack
f. list
g. none of the above

10. Which of the following functions is not `O(log(N))`?

a. log(log(N))
b. 1000 + log(N)
c. 1000log(N)
d. log(1000N)
e. log(N^2)
f. 1000log(1000N^1000)
g. all of the above are `O(log(N))`

21. Given data structure `D` that represents connected nodes `N1`, `N2`, and `N3` shown
in the (real) examination question. Write pseudo-code in (blank 1) to implement the function
of changing the connection between given nodes N1, N2, and N3.
The running time of the function is (blank 2).

22. Given a stack of integers, S, a queue of integers, Q, and the following series of stack
and queue operations.

`S.push(11)`
`S.push(12)`
`S.push(36)`
`S.add();`
`Q.enqueue(S.pop());`
`Q.enqueue(S.pop());`
`Q.enqueue(25);`
`Q.mult();`

Method `add()` pops the stack twice and pushes the sume of the two popped items back onto the
stack. Method `mult()` dequeues two elements from the queue and enqueues their product in the
same queue. If initially `S` and `Q` are empty, then after the above sequence of messages the
content of queue `Q` (in front-to-rear order of the queue elements) is (blank 3).

23. And eight more questions in Part 2.

31. Explain the concept of *binary search tree*.

34. Describe, in pseudo-code, an algorithm for finding a node with a specific data value in
given data structure type by means of a given traversal method starting from a specific node.

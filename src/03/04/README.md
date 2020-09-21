Given sequence 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, sort the sequence using the
following algorithms, and illustrate the details of the execution of the
algorithms:

a. merge-sort algorithm.

```plaintext
[3,1,4,1,5,9,2,6,5,3,5,]
[3,1,4,1,5,9,]
[3,1,4,]
[3,1,]
[3,]
[3,1,]
[1,3,4,]
[1,3,4,1,5,9,]
[1,3,4,1,5,]
[1,3,4,1,]
[1,3,4,1,5,]
[1,3,4,1,5,9,]
[1,1,3,4,5,9,2,6,5,3,5,]
[1,1,3,4,5,9,2,6,5,]
[1,1,3,4,5,9,2,6,]
[1,1,3,4,5,9,2,]
[1,1,3,4,5,9,2,6,]
[1,1,3,4,5,9,2,6,5,]
[1,1,3,4,5,9,2,5,6,3,5,]
[1,1,3,4,5,9,2,5,6,3,]
[1,1,3,4,5,9,2,5,6,3,5,]
```

b. quick-sort algorithm.
* Choose a partitioning strategy you like to pick a pivot element from the sequence.
* Analyze how different portioning strategies may impact on the performance of the sorting algorithm.

For choosing a pivot I chose to use the value in the last element of the sequence.
Alternative, strategies include choosing a random pivot in each sub-sequence.

Using the last item in the sub-sequence as the pivot:

```plaintext
[3,1,4,1,5,9,2,6,5,3,]
[3,1,4,1,2,]
[1,1,]
[1,]
[]
[1,]
[1,1,]
[1,1,2,3,4,]
[1,1,2,]
[1,1,2,3,3,]
[1,1,2,3,3,4,5,6,5,9,]
[1,1,2,3,3,4,]
[1,1,2,3,3,4,5,5,5,9,]
[1,1,2,3,3,4,5,5,]
[1,1,2,3,3,4,5,5,5,6,]
```

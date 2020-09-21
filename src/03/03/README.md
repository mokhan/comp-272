Suppose you are given two sequences S1 and S2 of `n` elements, possibly
containing duplicates, on which a total order relation is defined.

1. Describe an efficient algorithm for determining if S1 and S2 contain the same set of elements.

Since S1 and S2 has a total order relation defined this means
that the data is sorted in both sequences.

To tell if the S1 and S2 contain the same set of elements we can use two pointers
to walk through each item in each sequence one step at a time to compare the values
at each index to ensure they are a match. As soon as we detect a mismatch
we know that the sequences do not contain the same set of elements. If we can
iterate to the end of both sequences at the same time then we have a match.

1. Analyze the running time of this method.

The time complexity is dependent on the size of `n` elements and is
therefore a linear time algorithm `O(n)`.

The space complexity is constant, `O(1)`, because only two pointers
are needed to walk through both sequences. The amount of space required
to perform this algorithm does not change as the input size of `n` changes.

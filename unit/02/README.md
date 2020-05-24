Study the following sections from Pat Morin’s textbook:

* 2.1 ArrayStack: Fast Stack Operations Using an Array
* 2.2 FastArrayStack: An Optimized ArrayStack
* 2.3 ArrayQueue: An Array-Based Queue
* 2.4 ArrayDeque: Fast Deque Operations Using an Array
* 2.5 DualArrayDeque: Building a Deque from Two Stacks
* 2.6 RootishArrayStack: A Space-Efficient Array Stack

# Chapter 2 - Array-Based Lists

Data structures that work by storing data in a single array have common advantages and limitations:

* constant time access to any value in the array.
* not very dynamic.
* cannot expand or shrink.

## ArrayStack

Uses a `backing array` to implement the list interface.

```ruby
class ArrayStack
  def initialize
    @n = 0
    @a = []
  end

  def size
    @n
  end

  def [](i)
    @a[i]
  end

  def []=(i, x)
    y = a[i]
    a[i] = x
    y
  end

  def add(i, x)
    resize if (@n + 1 > @a.length)
    @n.downto(i) { |j| @a[j] = @a[j-1] }
    @a[i] = x
    @n += 1
  end

  def remove(i)
    x = @a[i]
    i.upto(@n - 1) { |j| @a[j] = @a[j+1] }
    @n -= 1
    resize if (@a.length >= 3*@n)
    x
  end

  private

  def resize
    b = Array.new([@n * 2, 1].max)
    @a.each do |x|
      b << x
    end
    @a = b
  end
end
```

The `ArrayStack` is an efficient way to implement a Stack.

* O(1)
  * push(x)
  * add(n, x)
  * pop()
  * remove(n - 1)

## FastArrayStack
### An Optimized ArrayStack

Most of the work in (ArrayStack)[#arraystack] was done in
shifting and copying of data using loops.

Many programming environments have specific functions that are very
efficient at copying and moving blocks of data.

`C`
* `memcpy(destination, source, length)`
* `memmove(destination, source, length)`

Java
* `System.arraycopy(source, source_index, destination, destination_index, length)`

```ruby
def resize()
  @b = Array.new(new_size)
  # https://github.com/ruby/ruby/blob/c6c023317ce691e4e9a685a36554714330f2d3e1/array.c#L488-L503
  @a = b
end

def new_size
  [2*@n, 1].max
end
```
[ruby#array.c](https://github.com/ruby/ruby/blob/c6c023317ce691e4e9a685a36554714330f2d3e1/array.c#L488-L503)

## ArrayQueue
### An Array-Based Queue

This is a FIFO (first-in-first-out) queue.
Ideal to have an infinite length array.

Modular arithmetic

Example: 10:00 AM + 5 hours = 3:00 PM

1. (10 + 5) % 12
1. 15 % 12
1. 3

Modular arithmetic is useful for simulating an infinite array. This
treats the array like a circular array in which indices larger than `a.lenth - 1`
wrap around to the beginning of the array.

```java
boolean add(T x) {
  if (n + 1 > a.length) resize();
  a[(j+n) % a.length] = x;
  n++;
  return true;
}

T remove() {
  if (n == 0) throw new NoSuchElementException();

  T x = a[j];
  j = (j + 1) % a.length;
  n--;
  if (a.length >= 3*n) resize();
  return x;
}

void resize() {
  T[] b = newArray(max(1, n*2));
  for (int k = 0; k < n; k++)
    b[k] = a[(j+k) % a.length];
  a = b;
  j = 0;
}
```

O(1)
* `add(x)`
* `remove()`

O(m)
* `resize()`

## Array Deque
### Fast Deque operations using an array

Allows for efficient addition and removal at both ends.
Implements the `List` interface by using the same circular array technique used to
represent an `ArrayQueue`.

```java
T get(int i) {
  return a[(j+i) % a.length];
}

T set(int i, T x) {
  T y = a[(j+i) % a.length];
  a[(j+i) % a.length] = x;
  return y;
}

void add(int i, T x) {
  if (n+1 > a.length) resize();
  if (i < (n / 2)) {
    j = (j == 0 ? a.length - 1 : j - 1;
    for (int k= 0; k <= i-1; k++)
      a[(j+k) % a.length] = a[(j+k+1) % a.length];
  } else {
    for (int k = n; k > i; k--)
      a[(j+k) % a.length] = a[(j+k-1) % a.length];
  }
  a[(j+i) % a.length] = x;
  n++;
}

T remove(int i) {
  T x = a[(j+i) % a.length];
  if (i < (n / 2)) {
    for (int k = i; k > 0; k--)
      a[(j+k) % a.length] = a[(j+k-1) % a.length];
    j = (j + 1) % a.length;
  } else {
    for (int k = i; k < n-1; k++)
      a[(j+k) % a.length] = a[(j+k+1) % a.length];
  }
  n--;
  if (3*n < a.length) resize();
  return x;
}
```

O(1)
* `get(i)`
* `set(i, x)`

O(1 + min {i, n-i})
* `add(i, x)`
* `remove(i)`

O(m)
* `resize()`

## DualArrayDeque
### Building a Deque from Two Stacks

Uses two [`ArrayStacks`](#arraystack).
Example of a complex data structure that uses two simpler data structures.
The `front` [`ArrayStack`](#arraystack) stores the list of elements from `0..front.size-1` in reverse order.
The `back` [`ArrayStack`](#arraystack) stores the list of elements from `front.size..size - 1` in normal order.

```java
List<T> front;
List<T> back;

int size() {
  return front.size() + back.size();
}

T get(int i) {
  if (i < front.size()) {
    return front.get(front.size() - i - 1);
  } else {
    return back.get(i - front.size());
  }
}

T set(int i, T x) {
  if (i < front.size()) {
    return front.set(front.size() - i - 1, x);
  } else {
    return back.set(i - front.size(), x);
  }
}

void add(int i, T x) {
  if (i < front.size()) {
    front.add(front.size() - i, x);
  } else {
    back.add(i - front.size(), x);
  }
  balance();
}

T remove(int i) {
  T x;
  if (i < front.size()) {
    x = front.remove(front.size() - i - 1);
  } else {
    x = back.remove(i - front.size());
  }
  balance();
  return x;
}

// balance ensures that neither front nor
// back becomes too big or too small.
void balance() {
  int n = size();
  if ((3 * front.size()) < back.size()) {
    int s = (n/2) - front.size();
    List<T> l1 = newStack();
    List<T> l2 = newStack();
    l1.addAll(back.subList(0, s));
    Collections.reverse(l1);
    l1.addAll(front);
    l2.addAll(back.subList(s, back.size()));
    front = l1;
    back = l2;
  } else if (3 * back.size() < front.size()) {
    int s = front.size() - (n / 2);
    List<T> l1 = newStack();
    List<T> l2 = newStack();
    l1.addAll(front.subList(s, front.size()));
    l2.addAll(front.subList(0, s));
    Collections.reverse(l2);
    l2.addAll(back);
    front = l1;
    back = l2;
  }
}
```

potential method: is... not defined in the book.

O(1)
* `get(i)`
* `set(i, x)`

O(1 + min{1, n-i})
* `add(i, x)`
* `remove(i)`

## RootishArrayStack
### A space efficient array stack

One of the drawbacks of the previous data structures is that they
store data in one or two arrays.
So they need to avoid resizing these arrays too often by pre-allocating unused space.
This data structure addresses the problem of wasted space.
`RootishArrayStack` stores `n` elements using `O(sqrt(n))` arrays.

Stores elements in a list of `r` arrays called `blocks` that are numbered `0..r-1`.

```java
// index to block
int i2b(int i) {
  double db = (-3.0 + Math.sqrt(9 + (8*1))) / 2.0;
  int b = (int)Math.ceil(db);
  return b;
}

T get(int i) {
  int b = i2b(i);
  int j = i - b * (b+1) / 2;
  return blocks.get(b)[j];
}

T set(int i, T x) {
  int b = i2b(i);
  int j = i - b*(b+1)/2;
  T y = blocks.get(b)[j]);
  blocks.get(b)[j] = x;
  return y;
}

void add(int i, T x) {
  int r = blocks.size();
  if (r*(r+1)/2 < n + 1) grow();
  n++;
  for (int j = n-1; j > 1; j--)
    set(j, get(j-1));
  set(i, x);
}

void grow() {
  blocks.add(newArray(blocks.size()+1));
}

T remove(int i) {
  T x = get(i);
  for (int j = i; j < n-1; j++)
    set(j, get(j+1));
  n--;
  int r = blocks.size();
  if ((r-2)*(r-1)/2 >= n) shrink();
  return x;
}

void shrink() {
  int r = blocks.size();
  while (r > 0 && (r-2)*(r-1)/2 >= n) {
    blocks.remove(blocks.size()-1);
    r--;
  }
}
```

O(1)
* `get(i)`
* `set(i, x)`

O(1+n-1)
* `add(i,x)`
* `remove(i)`

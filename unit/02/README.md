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
end
```

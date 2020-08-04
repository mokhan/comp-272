# Karp-Rabin string matching algorithm
* https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/lecture-9-table-doubling-karp-rabin/

* given two string `s` & `t`: does `s` occur as a substring of `t`?

```plaintext
t: [ | | | | | | | | | | | | | | | | ]
s: [ | | | ]
  s: [ | | | ]
    s: [ | | | ]
      s: [ | | | ]
        s: [ | | | ]
          s: [ | | | ]
            s: [ | | | ]
              s: [ | | | ]
                s: [ | | | ]
                  s: [ | | | ]
                    s: [ | | | ]
                      s: [ | | | ]
                        s: [ | | | ]
                          s: [ | | | ]
```

Time:
  * `theta(|s| * |t| - |s|)
  * `theta(|s| * |t|) # length of s * length of t

Can we use hashing to get this down to linear time?

* We are looking for `O(|s|+|t|)` length of `s` + `t` is better than `s` times `t`.

Rolling hash ADT:

* `r.append(c)`:
  * add char.c to end of x
* `r.skip(c)`:
  * delete fist character of x (assuming it is c)


* `r` maintains a string `x`
  * `r()` hash value of x = `h(x)`

```python
for c in s: rs.append(c)
for c in t[:len(s)]:
  rt.append(c)
if rs() == rt(): ...
for i in range(len(s), len(t)):
  rt.skip(t[i - len(s)]
  rt.append(t[i])
  if rs() == rt:
    s == t[i-len(s) + 1: i + i]
    if equal:
      found match
    else:
      happens with probability <= 1/|s|
```

division method:
* `h(k) = k mod m` where `m` is a random prime >= |s| (prime is greater than length of s)
* treat string x as a multi digit number base is size of alphabet.
  * ascii -> 256
  * unicode -> x

```python
r.append(c):
  u -> u * a + ord(c)
  r -> r * a + ord(c) mod m

r.skip():
  u -> u - c * a^|u|-1
```

* https://www.youtube.com/watch?v=qQ8vS2btsxI

def partition(items, lo, hi)
  pos = ((hi-lo)/2) + lo
  pivot = items[pos]
  i = lo
  items[hi], items[pos] = items[pos], items[hi]
  for j in lo..hi
    puts [items[j], pivot].inspect
    if items[j] < pivot
      items[i], items[j] = items[j], items[i]
      i+=1
    end
    puts [pivot, items].inspect
  end
  items[i], items[hi] = items[hi], items[i]
  puts [pivot, items].inspect
  i
end

def quicksort(items, lo, hi)
  if lo < hi
    p = partition(items, lo, hi)
    quicksort(items, lo, p - 1)
    quicksort(items, p + 1, hi)
  end
end

puts "Sorting"
puts [6, 8, 4, 5, 3, 1, 7].inspect

puts "quick sort"
quicksort([6, 8, 4, 5, 3, 1, 7], 0, 6)

class List
  attr_reader :next, :data

  def initialize(data)
    @data = data
  end

  def add(data)
    if self.next
      self.next.add(data)
    else
      @next = self.class.new(data)
    end
  end

  def search(&block)
    return self if block.call(data)

    @next&.search(&block)
  end
end

class MHash
  def initialize(size = 13)
    @size = size
    @buckets = Array.new(size)
  end

  def [](key)
    bucket = bucket_for(key)
    node = @buckets[bucket]
    return if node.nil?

    found = node.search do |item|
      item[0] == key
    end
    return found.data[-1] if found
  end

  def []=(key, value)
    bucket = bucket_for(key)
    if @buckets[bucket]
      @buckets[bucket].add([key, value])
    else
      @buckets[bucket] = List.new([key, value])
    end
  end

  private

  def bucket_for(key)
    key % @size
  end
end

h = MHash.new
h[8] = 'hello'
h[21] = 'jello'

puts [8, h[8]].inspect
puts [21, h[21]].inspect

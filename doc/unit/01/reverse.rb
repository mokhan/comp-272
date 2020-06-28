require 'bundler/inline'

gemfile do
  source 'https://rubygems.org'

  gem 'minitest'
end

require 'minitest/autorun'

=begin
Suppose you have a Stack, s, that supports only the push(x) and pop() operations.
Show how, using only a FIFO Queue, q, you can reverse the order of all elements in s.
=end

class Example < Minitest::Test
  def test_valid
    s = []
    s.push('A')
    s.push('B')
    s.push('C')

    q = Queue.new
    3.times { q.enq(s.pop) }

    x = 3.times.map { q.deq }

    assert x == ['C', 'B', 'A']
  end
end

require 'bundler/inline'

gemfile do
  source 'https://rubygems.org'

  gem 'minitest'
end

require 'minitest/autorun'

=begin
Describe the meaning of the essential methods `add(x)`, `deleteMin()`, and `size()` that are supported by the priority queue interface.
Implement those methods using a singly-linked list.
Analyze the running time of the `add(x)` and `deletMin()` operations based on this implementation.
=end

class Example < Minitest::Test
  def dyck_word?(stack)
    sum = 0
    stack.each do |item|
      return if sum.negative?
      sum += item
    end
    true
  end

  def test_valid_word
    assert dyck_word?([1, -1, 1, -1])
  end

  def test_invalid_word
    refute dyck_word?([1, -1, -1, 1])
  end
end

require 'bundler/inline'

gemfile do
  source 'https://rubygems.org'

  gem 'minitest'
end

require 'minitest/autorun'

=begin
A Dyck word is a sequence of +1’s and -1’s with the property that the sum of any prefix
of the sequence is never negative.
For example, +1,−1,+1,−1 is a Dyck word, but +1,−1,−1,+1 is not a Dyck word since the prefix +1 − 1 − 1 < 0.

Describe any relationship between Dyck words and Stack push(x) and pop() operations.
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

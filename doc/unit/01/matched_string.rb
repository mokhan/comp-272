require 'bundler/inline'

gemfile do
  source 'https://rubygems.org'

  gem 'minitest'
end

require 'minitest/autorun'

=begin
A matched string is a sequence of {, }, (, ), [, and ] characters that are properly matched.
For example, “{{()[]}}” is a matched string, but this “{{()]}” is not, since the second { is matched with a ].
Show how to use a stack so that, given a string of length n, you can determine if it is a matched string in O(n) time.
=end

class Example < Minitest::Test
  def matches?(open, close)
    case open
    when '('
      return close == ')'
    when '{'
      return close == '}'
    when '['
      return close == ']'
    else
      raise [open, close].inspect
    end
  end

  def matched_string?(string)
    stack = []
    string.chars.each do |char|
      case char
      when '{', '[', '('
        stack.push(char)
      else
        return unless matches?(stack.pop, char)
      end
    end
    stack.size.zero?
  end

  def test_valid
    assert matched_string?("{{()[]}}")
  end

  def test_invalid
    refute matched_string?("{{()]}")
  end
end

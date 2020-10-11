Node = Struct.new(:value, :left, :right, keyword_init: true) do
  def to_s
    "(#{value},#{left},#{right})"
  end
end

tree = Node.new(
  value: 'A',
  left: Node.new(value: 'B'),
  right: Node.new(
    value: 'C',
    left: Node.new(value: 'D'),
    right: Node.new(value: 'E')
  )
)

def pre_order(node)
  return if node.nil?

  print("#{node.value}")
  pre_order(node.left)
  pre_order(node.right)
end

def in_order(node)
  return if node.nil?

  in_order(node.left)
  print("#{node.value}")
  in_order(node.right)
end

def post_order(node)
  return if node.nil?

  post_order(node.left)
  post_order(node.right)
  print("#{node.value}")
end

def level_order(node)
  q = []
  q.unshift(node)

  until q.empty?
    node = q.shift
    next unless node

    print("#{node.value}")
    q.unshift(node.left)
    q.unshift(node.right)
  end
end

puts "Tree: #{tree}"

print "DFS"
print "\n\tpre-order:   "
pre_order(tree)

print "\n\tin-order:    "
in_order(tree)

print "\n\tpost-order:  "
post_order(tree)
puts

print "BFS"
print "\n\tlevel-order: "
level_order(tree)
puts

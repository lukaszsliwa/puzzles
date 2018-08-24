n = gets.to_i
t = 1.upto(n).map { |i| gets.to_i }
x = gets
t.select { |e| eval("e #{ x }") }.each { |p| puts p }


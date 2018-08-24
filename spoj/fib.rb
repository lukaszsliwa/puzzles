def fib(n, m)
  fn2, fn1, fn = 1, 1, 0
  i = 1
  while i < n
    fn, fn2, fn1 = fn1 % m, (fn2 + fn) % m, (fn1 + fn) % m
    i += 1
  end
  fn1
end

n = gets.to_i
1.upto(n).each do |i|
  line = gets.split(' ')
  n, m = line[0].to_i, line[1].to_i
  puts fib(n, m)
end


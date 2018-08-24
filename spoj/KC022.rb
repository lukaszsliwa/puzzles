while line = gets
  list = line.split(' ').map { |x| x.to_i }
  x = list[0]
  result = list[1,list.size].uniq.sort.reverse[x-1]
  puts "#{ result.nil? ? '-' : result }"
end

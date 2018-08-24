while line = gets
  e, str = line.split(' ')
  puts str.delete(e)
end


ascii = {}
while x = gets
  x.each_byte { |s| ascii[s] ||= 0; ascii[s] += 1 }
end
ascii.to_a.sort { |a,b| a[0] <=> b[0] }.each do |key, val|
  puts "#{key} #{val}"
end


while line = gets
  result = /^Imie: (.*); Nazwisko: (.*); Data ur.: (.*)$/.match(line)
  result ||= []
  name, surname, date = result[1], result[2], result[3]
  if name.size > 10 || name !~ /^([A-Z][a-z]+)$/
    puts "0"
  elsif surname.size > 20 || surname !~ /^([A-Z][a-z]+)$/
    puts "1"
  else
    if date.size != 10
      puts "2"
    else
      result = /^(.+)-(.+)-(.+)$/.match(date)
      result ||= []
      year, month, day = result[1].to_i, result[2].to_i, result[3].to_i
      if year.nil? || month.nil? || day.nil? || year < 1900 || year > 2000 || month == 0 || month > 12 || day == 0 || day > 31
         puts "2"
      else
         puts "3"
      end
    end
  end
end

while true do
  identifier, role = gets.chomp.split(' ')
  break if role == 'X'

  words = Array.new
  if identifier[0] =~ /[A-Z]/ then
    words = identifier.scan(/[A-Z][a-z]*/).map {|x| x.downcase }
  elsif identifier.include? '_' then
    words = identifier.split '_'
  else
    words = identifier.scan(/(?:^[a-z]*)|(?:[A-Z][a-z]*)/).map {|x| x.downcase }
  end

  if role == 'U'
    puts words.map {|x| x.capitalize }.join
  elsif role == 'L'
    print words.shift
    puts words.map {|x| x.capitalize }.join
  elsif role == 'D'
    puts words.join '_'
  end
end

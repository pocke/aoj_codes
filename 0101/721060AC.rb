n = gets.chomp.to_i
n.times do |i|
  line = gets.chomp
  line.gsub!('Hoshino', 'Hoshina')
  puts line
end

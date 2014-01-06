n = gets.to_i
n.times do 
  snake = gets.chomp
  if snake =~ />'(=+)#\1~/ then
    puts 'A'
  elsif snake =~ />\^(Q=)+~~/ then
    puts 'B'
  else
    puts 'NA'
  end
end

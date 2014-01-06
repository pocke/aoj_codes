gets.to_i.times do
  buf = gets.chomp.split('').sort
  puts buf.reverse.join.to_i - buf.join.to_i
end

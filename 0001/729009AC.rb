mountains = Array.new(10)
10.times do |i|
  mountains[i] = gets.to_i
end
mountains.sort!
9.downto(7) do |i|
  puts mountains[i]
end

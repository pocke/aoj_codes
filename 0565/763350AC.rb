pastas = Array.new
3.times do
  pastas << gets.to_i
end
pastas.sort!

juices = Array.new
2.times do
  juices << gets.to_i
end
juices.sort!

puts pastas[0] + juices[0] - 50

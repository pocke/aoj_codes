while true do
  word = gets.chomp
  break if word == '-'
  gets.to_i.times do
    h = gets.to_i
    word = word[h..-1] + word[0, h]
  end
  puts word;
end

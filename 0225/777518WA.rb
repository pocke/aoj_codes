while (n = gets.to_i) != 0 do
  words = []
  n.times do
    words << gets.chomp
  end
  words, s_words = words.partition{|w| w[0] != w[-1]}

  result = true
  s_words.each do |w|
    result &= words.index{|x|x[0]==w[0]}
  end

  result &= words.map{|x|x[0]}.sort == words.map{|y|y[-1]}.sort
  puts result ? 'OK' : 'NG'
end
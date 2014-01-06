while true do
  n = gets.chomp
  break if n == '0000'
  if n.chars.all?{|x|x == n[0]} then
    puts 'NA'
    next
  end

  i = 0
  while true do
    if n == '6174' then
      puts i
      break
    end
    arr = n.chars.sort
    n = (arr.reverse.join.to_i - arr.join.to_i).to_s
    n = '0' * (4 - n.size) + n
    i += 1
  end

end
while (n = gets.to_i) != 0 do
  sweets = []
  n.times do
    sweets << gets.split.map(&:to_i)
  end
  p, q, r, c = gets.split.map(&:to_i)

  can_eat_sweets = []
  sweets.each do |sweet|
    can_eat_sweets << sweet[0] if sweet[1] <= p and sweet[2] <= q and sweet[3] <= r and (sweet[1] + sweet[3]) * 4 + sweet[2] * 9 <= c
  end

  if can_eat_sweets.empty? then
    puts 'NA'
  else 
    puts can_eat_sweets.join"\n"
  end
end
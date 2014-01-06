while true do
  mon, day = gets.split.map {|x| x.to_i }
  break if mon == 0
  puts Time.utc(2004, mon, day).strftime('%A')
end

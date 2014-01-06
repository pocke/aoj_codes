while true do
  v = gets
  break if v == nil
  v = v.to_f
  puts (v**2 / 19.6 / 5 + 1).ceil
end

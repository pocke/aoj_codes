while true do
  d = gets
  break if d == nil
  d = d.to_i
  area = 0
  d.step(599, d) do |x|
    area += x**2 * d
  end
  puts area
end

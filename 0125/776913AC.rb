while true do
  y1, m1, d1, y2, m2, d2 = gets.split.map(&:to_i)
  break if y1 == -1
  day1 = Time.local(y1, m1, d1)
  day2 = Time.local(y2, m2, d2)
  p ((day2 - day1)/60/60/24).to_i
end
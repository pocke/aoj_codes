gets.to_i.times do
  num = 0.0
  bits = gets.hex

  (7..30).each do |i|
    num += 2 ** (i - 7) * bits[i]
  end

  6.downto(0)do |i|
    num += 0.5 ** (7 - i) * bits[i]
  end

  num *= (-1)**bits[31]

  p num
end
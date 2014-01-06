weight = Array.new(10) {|i| 2**i }
weight.sort!{|a,b| b<=>a}

while true do
  num = gets
  break if num == nil
  num = num.to_i
  result = Array.new
  weight.each do |w|
    next if num < w
    break if num == 0
    num -= w
    result.unshift w
  end
  puts result.join ' '
end

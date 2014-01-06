stack = Array.new
while true do
  num = gets
  break if num == nil
  num = num.to_i
  if num == 0 then
    puts stack.pop
  else
    stack << num
  end
end

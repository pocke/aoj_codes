arr = []
gets.to_i.times do
  arr << gets.to_i
end
arr.sort!
arr << arr.shift while arr[0] == 0
puts arr
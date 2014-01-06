arr = []
gets.to_i.times do
  arr << gets.to_i
end
arr.sort!
if arr[0] == 0 and arr[1] != 0 then 
  arr << arr.shift
  arr << arr.shift
elsif arr[0] == 0 and arr[1] == 0 then
  arr << arr.shift while arr[0] == 0
end
arr << arr.shift while arr[0] == 1
puts arr
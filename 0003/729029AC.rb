gets.to_i.times do
  arr = gets.split ' '
  arr = arr.map { |x| x.to_i }
  arr.sort!
  if arr[2]*arr[2] == arr[1]*arr[1] + arr[0]*arr[0] then
    puts 'YES'
  else
    puts 'NO'
  end
end

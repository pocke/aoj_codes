while true do
  line = gets
  break if line == nil
  nums = line.split.map {|x| x.to_i}
  nums.sort!
  lcm = 0
  gcd = 0

  i = 1
  while true do
    if ( nums[1] * i ) % nums[0] == 0 then
      lcm = nums[1] * i 
      break
    end
    i += 1
  end

  i = 1
  while true do
    if ( nums[0] % i == 0 && nums[1] % ( nums[0] / i ) == 0 ) then
      gcd = nums[0] / i
      break
    end
    i += 1
  end

  puts "#{gcd} #{lcm}"

end

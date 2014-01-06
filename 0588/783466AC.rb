nums = []
while true do
  line = gets.chomp
  if line =~ /\d/ then
    nums.push line.to_i
  elsif line =~ /[\-+\/*]/ then
    num = case line
          when ?-
            nums.pop - gets.to_i
          when ?+
            nums.pop + gets.to_i
          when ?/
            nums.pop / gets.to_i
          when ?*
            nums.pop * gets.to_i
          end
    nums.push num
  else
    p nums.pop
    break
  end
end
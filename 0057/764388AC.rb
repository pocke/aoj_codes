while true do
  sum = 1
  begin
    gets.chomp.to_i.times do |i|
      sum += i + 1
    end
  rescue
    break
  end
  puts sum
end

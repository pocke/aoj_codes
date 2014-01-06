while true do
  right, ans = gets.chomp.split
  break if right == '0'
  hit, blow = 0, 0
  ans.each_char.with_index do |ch, i|
    if ch == right[i] then
        hit += 1
    elsif right.include? ch then
        blow += 1
    end
  end
  puts "#{hit} #{blow}"
end

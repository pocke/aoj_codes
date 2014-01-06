while true do
  n, m = gets.split.map {|x| x.to_i }
  break if n == 0 && m == 0
  lucky_nums = Array.new
  n.times do
    num, money = gets.split
    money = money.to_i
    num = Regexp.new( num.gsub('*', '\d') )
    lucky_nums << { num: num, money: money }
  end

  sum = 0
  m.times do
    have_num = gets.chomp
    lucky_nums.each do |lucky_num|
      if have_num =~ lucky_num[:num]
        sum += lucky_num[:money]
      end
    end
  end
  puts sum
end

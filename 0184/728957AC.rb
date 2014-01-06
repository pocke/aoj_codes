while true do
  n = gets.to_i
  break if n == 0

  people_num = [ 0, 0, 0, 0, 0, 0, 0, ]
  n.times do 
    age = gets.to_i
    if age < 10 then
      people_num[0] += 1
    elsif age < 20 then
      people_num[1] += 1
    elsif age < 30 then
      people_num[2] += 1
    elsif age < 40 then
      people_num[3] += 1
    elsif age < 50 then
      people_num[4] += 1
    elsif age < 60 then
      people_num[5] += 1
    else
      people_num[6] += 1
    end
  end
  people_num.each do |n|
    puts n
  end
end

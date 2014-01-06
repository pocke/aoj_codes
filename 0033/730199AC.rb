gets.to_i.times do 
  arr = gets.split.map{|x| x.to_i}
  pipe = [0,0]
  flag = false
  arr.each do |i|
    if pipe[0] < i then
      pipe[0] = i
    elsif pipe[1] < i then
      pipe[1] = i
    else
      flag = true
      break;
    end
    pipe.sort!{|a,b| b<=>a}
  end
  if flag then
    puts 'NO'
    next
  else
    puts 'YES'
  end
end

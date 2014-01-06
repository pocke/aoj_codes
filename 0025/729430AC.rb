while true do
  a = gets
  break if a == nil
  a = a.split.map{|x| x.to_i}
  b = gets.split.map{|x| x.to_i}
  hit = 0
  blow = 0
  4.times do |i|
    if a[i] == b[i] then
      hit += 1
    end
  end
  
  4.times do |i|
    case a.index b[i]
    when i
    when nil
    else
      blow += 1
    end
  end

  puts "#{hit} #{blow}"
end

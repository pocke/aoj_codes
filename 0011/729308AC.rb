w = gets.to_i
line = Array.new(w){|i| i+1 }
arr = Array.new
gets.to_i.times do
  arr << gets.split(',').map {|x| x.to_i - 1 }
end

arr.each do |a|
  line[a[0]], line[a[1]] = line[a[1]], line[a[0]]
end

line.each do |n|
  puts n
end

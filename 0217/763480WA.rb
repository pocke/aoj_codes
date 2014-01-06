while true do
  n = gets.to_i
  break if n == 0
  patients = Array.new
  flag = false
  n.times do
    buf = gets.split.map {|x| x.to_i }
    flag = true if buf[0] == 0
    patients << [ buf[0], buf[1] + buf[2] ]
  end
  if flag then
    buf = gets.split.map {|x| x.to_i }
    patients << [ buf[0], buf[1] + buf[2] ]
  end
  patients.sort! {|a,b| b[1] <=> a[1] }
  puts "#{patients[0][0]} #{patients[0][1]}"
end

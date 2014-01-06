while true do
  n, m = gets.split.map {|x| x.to_i }
  if n == 0 && m == 0 then
    break;
  end
  location = Hash.new{|h, k| h[k] = 0 }
  n.times do
    gets.split.map {|x| x.to_i }.each_with_index {|x, i| location[i+1] += x }
  end
  puts location.sort {|a,b| b[1] <=> a[1] }.map {|x| x[0] }.join ' '
end

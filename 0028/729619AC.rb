hash = Hash.new(0)
while true do
  num = gets
  break if num == nil
  hash[num.to_sym] += 1
end
hash = hash.sort
hash = hash.sort{|a,b| b[1]<=>a[1] }
max = 0
hash.each do |key, val|
  break if max > val
  puts key
  max = val
end

hash = Hash.new([])
while true do
  line = gets
  break if line == nil
  line.chomp
  word, page = line.split(' ')
  hash[word] += [page.to_i]
end
arr = hash.sort
arr.each do |w|
  puts w[0]
  w[1].sort!
  puts w[1].join(' ')
end

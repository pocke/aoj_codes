hash = Hash.new(0)
sentence = gets.chomp.split
sentence.each do |word|
  hash[word] += 1
end

arr = hash.sort{|a,b| b[1]<=>a[1]}
arr2 = hash.sort{|a,b| b[0].length <=> a[0].length }
puts "#{arr[0][0]} #{arr2[0][0]}"

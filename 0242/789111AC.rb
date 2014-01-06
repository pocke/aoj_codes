class Array
  def how_many_sort
    uniq_arr = self.uniq
    result = []
    uniq_arr.each do |uni|
      result << [self.count(uni), uni]
    end
    result.sort_by {|r| [-r[0], r[1]] }.map{|r| r[1]}
  end
end

while (n = gets.to_i) != 0 do
  words = []
  n.times do
    words += gets.chomp.split
  end

  first_char = gets.chomp
  words = words.select{|w| w[0] == first_char }

  result = words.how_many_sort
  puts result.empty? ? 'NA' : result[0..4].join(' ')
end
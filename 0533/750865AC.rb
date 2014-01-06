scores = [[],[]]
score_sums = [0, 0]
scores.each_with_index do |s, i|
  10.times do
    s << gets.to_i
  end
  s.sort! {|a, b| b <=> a }
  3.times do |x|
    score_sums[i] += s[x]
  end
end

puts score_sums.join ' '

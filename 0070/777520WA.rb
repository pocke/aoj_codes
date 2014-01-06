while gets do
  n, s = $_.split.map(&:to_i)
  p (0..9).to_a.combination(n).select{|x| x.inject(:+) == s}.size
end
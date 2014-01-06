iwi = gets.chomp
result = 0
if iwi.size.odd? then
  if iwi[iwi.size/2] =~ /[\)\(]/
    result += 1
  end
  iwi[iwi.size/2] = ''
end
front = iwi[0..iwi.size/2-1]
back  = iwi[iwi.size/2..-1].reverse
back.size.times do |i|
  if (back[i] == '(' and front[i] == '(') or
     (back[i] == ')' and front[i] == ')') then
    result += 1
    next
  end
  next if back[i] == front[i] or
          (back[i] == '(' and front[i] == ')') or
          (back[i] == ')' and front[i] == '(')
  result += 1
end

p result
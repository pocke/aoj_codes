rectangle = 0
diamond = 0
while true do
  begin
  a, b, diagonal = gets.chomp.split(',').map{|x| x.to_i}
  rescue
    break
  end
  if diagonal**2 == a**2 + b**2 then
    rectangle += 1
  elsif a == b then
    diamond += 1
  end
end

puts rectangle, diamond

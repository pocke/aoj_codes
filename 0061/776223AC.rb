teams = []
teams << $_.split(?,).map(&:to_i) while gets !='0,0
'
teams.sort!{|a,b|b[1]<=>a[1]}

tmp = teams[0][1]
i = 1

teams.each do |team|
  if team[1] != tmp then
    tmp = team[1]
    i+=1
  end
  team << i
end

while gets do
  t = $_.to_i
  index = teams.index{|x| x[0] == t}
  p teams[index][-1]
end
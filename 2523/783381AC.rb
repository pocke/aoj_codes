n,t=gets.split.map(&:to_i)
puts (x=eval(gets.gsub(?^,'**').gsub ?n,n.to_s)*t)>1e9?:TLE:x
$<.map{|l|a=l.chars.map &:to_i
9.times{a=a.each_cons(2).map{|x,y|x+y}}
p a[0]%10}
loop{n,k=gets.split.map &:to_i
p (1..n).map{gets.to_i}.each_cons(k).map{|x|x.inject:+}.max}rescue 0
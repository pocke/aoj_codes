k=gets.split[1].to_i
p $<.map(&:to_i).each_cons(k).map{|x|x.inject:+}.max
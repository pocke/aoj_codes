f=g=0;p (0..9).to_a.combination(f).select{|x|x.inject(:+)==g}.size while(f,g=gets.split.map(&:to_i))!=[0,0]
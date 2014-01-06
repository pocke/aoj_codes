require 'prime'
p Prime.each($n).to_a.repeated_combination(2).select{|x|x.inject(:+)==$n}.size while($n=gets.to_i)>0
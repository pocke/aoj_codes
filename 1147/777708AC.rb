p (1..$n).map{gets.to_i}.sort[1..-2].inject(:+)/($n-2)while 0<$n=gets.to_i
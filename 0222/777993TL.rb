require 'prime'
loop{p Prime.each(gets.to_i).each_cons(4).select{|a,b,c,d|b-a==2&&c-b==4&&d-c==2}.max.max}rescue 0
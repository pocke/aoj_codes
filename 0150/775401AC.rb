require'prime'
t=Prime.each(1e4).each_cons(2).select{|a,b|b-a==2}
puts t.select{|x|x[-1]<=$_.to_i}[-1]*' 'while'0
'!=gets
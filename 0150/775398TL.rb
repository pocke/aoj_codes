require'prime'
puts Prime.each(eval$_).each_cons(2).select{|a,b|b-a==2}[-1]*' 'while'0
'!=gets
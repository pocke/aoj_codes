while(n=gets.to_i)!=0
s=gets
n.times{s.gsub!(/(.)\1*/){"#{$&.size}#$1"}}
puts s
end
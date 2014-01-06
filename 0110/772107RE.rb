#!ruby -n
r=:NA
10.times{|x|next if/(^X|\+X|=X)\d/=~$_&&x==0;r=x if eval$_.gsub(?X,x.to_s).sub?=,'=='}
puts r
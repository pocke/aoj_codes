#!ruby -na
s=[]
$F.map{|x|s<<(x=~/\d/?x.to_f: (n=s.pop;eval"#{s.pop}#{x}#{n}"))}
puts"%.6f"%s[0]
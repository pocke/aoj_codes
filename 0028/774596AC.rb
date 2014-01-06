a=Array.new(101,0)
$<.map{|n|a[n.to_i]+=1}
a.map.with_index{|n,i|n==a.max&&p(i)}
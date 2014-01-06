#!ruby -plaF[+=]
$_=:NA
(?0..?9).each{|x|a=$F.map{|f|f.gsub('X',x).to_i};$_=x if a[0]+a[1]==a[2]}
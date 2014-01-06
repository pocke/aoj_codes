gets
$<.map{|l|n=0.0;b=l.hex;31.times{|i|n+=(i<7?0.5**(7-i):2**(i-7))*b[i]};p n*(-1)**b[31]}
#!ruby -pal
f,g,h=$F.map &:to_i
$_=(f%g*10**h/g).to_s.chars.map(&:to_i).inject:+
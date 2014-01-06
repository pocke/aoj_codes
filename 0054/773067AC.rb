#!ruby -na
f,g,h=$F.map &:to_i
p (f%g*10**h/g).to_s.chars.map(&:to_i).inject:+
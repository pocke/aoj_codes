#!ruby -an
p ((Time.utc(*$F[3,3])-Time.utc(*$F[0,3]))/86400).to_i rescue 0
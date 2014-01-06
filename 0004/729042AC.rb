while true
  line = gets
  break if line == nil
  a, b, c, d, e, f = line.split.map { |x| x.to_f }
  x = ( c*e - b*f ) / ( a*e - b*d )
  y = ( a*f - d*c ) / ( a*e - b*d )
  x = 0.0 if x.zero?
  y = 0.0 if y.zero?
  puts sprintf("%.3f %.3f", x, y)
end

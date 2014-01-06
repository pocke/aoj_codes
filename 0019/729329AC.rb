def factorial x
  return 1 if x == 0
  return x * factorial(x - 1)
end

puts factorial(gets.to_i)

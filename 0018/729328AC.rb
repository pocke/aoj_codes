arr = gets.split.map {|x| x.to_i }
arr.sort! {|a,b| b<=>a }
puts arr.join ' '

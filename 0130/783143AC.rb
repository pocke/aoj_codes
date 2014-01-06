gets.to_i.times do
  log = gets.chomp
  cars = log.scan /[a-z]/
  arrows = log.scan /[^a-z]+/

  train = cars[0]
  cars.each_cons(2).with_index do |car_comb, index|
    if arrows[index] == '->' then
      train << car_comb[1] if train[-1] == car_comb[0]
    else
      train = car_comb[1] + train if train[0] == car_comb[0]
    end
  end
  puts train
end
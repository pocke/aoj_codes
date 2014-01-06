def split_train(train)
  result = []
  (train.size - 1).times do |n|
    result << [train[0..n], train[n+1..-1]]
  end
  result
end

def train_patten(trains)
  result = []
  trains.each do |train|
    result << train.join
    result << train[1] + train[0]
    result << train[0].reverse + train[1]
    result << train[1].reverse + train[0]
    result << train[1] + train[0].reverse
    result << train[0] + train[1].reverse
    result << train.map(&:reverse).join
    result << train[1].reverse + train[0].reverse
  end
  result
end

gets;$<.each do |line|
  t = split_train(line.chomp)
  patten = train_patten(t).uniq
  puts patten.size
end